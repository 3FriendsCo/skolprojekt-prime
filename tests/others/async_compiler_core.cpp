#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <time.h>
#include <future>
#include <thread>

#include "include/error.h"
#include "include/prime_ast.h"
#include "include/Cpp.h"
#include "include/Token.h"
#include "include/color_lib.h"
#include "config/config.h"

static void log_usage(char** argv, int argc/*, mode*/) { //Logs the usage of the program
    ANSI_COLOR_OUTPUT(("USAGE: [" + std::to_string(argc) + "] " + "<" + argv[0] + ">\n"), "BrightYellow",{"Italic","Bold","Underline"});
}

struct Token {
    Token_type type;
    std::string value;
    //META DATA:
    int position, row;
    std::string line;
};

struct AST_node {
    AST_node_type type;
    int value;
    std::vector<AST_node*> children;
};

Token_type match_to_prime_keyword(const std::string keyword);

class Lexer {
public:
    std::vector<Token> lex(clock_t compiletime_start, std::ofstream* log_file, std::ifstream* prime_file) {
        int current_pos, row = 0;
        char current_char, previous_char = 0;
        std::vector<Token> tokens;
        std::string keyword, line;

        while (std::getline(*prime_file, line)) {
            row++;
            line.push_back(' ');
            for (size_t i = 0; i < line.length(); i++) {
                current_pos = i;
                current_char = line[current_pos];

                if (std::isspace(current_char)) {
                    if(prime_error::lexer::error_counter() == 0) {
                        ANSI_COLOR_OUTPUT("ERROR\n", "BrightRed");
                    }
                    prime_error::lexer::log_error(compiletime_start, 511, current_pos, row, current_char, line);
                    prime_error::lexer::error_counter(1);
                    if (isalpha(previous_char)) {
                        tokens.emplace_back(Token{match_to_prime_keyword(keyword), keyword, current_pos, row, line});
                        keyword.clear();
                    }
                    //tokens.emplace_back(Token{SPACE, " "}); PRETTY UNECESSARY
                    //If error, do error and "continue;"
                } else if (!std::isalnum(current_char)) {
                    if (std::isalpha(previous_char)) {
                        tokens.emplace_back(Token{match_to_prime_keyword(keyword), keyword, current_pos, row, line});
                        keyword.clear();
                    }

                    if (current_char == '\"') {
                        std::string message;
                        message += current_char;
                        while (++i < line.length() && (current_char = line[i]) != '\"') {
                            message += current_char;
                            if (current_char == '\\') {
                                message += line[++i];
                            }
                        }
                        message += current_char;
                        tokens.emplace_back(Token{MESSAGE, message, current_pos, row, line});

                    } else if (current_char == '\'') {
                        std::string character;
                        character += current_char;
                        while (++i < line.length() && (current_char = line[i]) != '\'') {
                            character += current_char;
                        }
                        character += current_char;
                        tokens.emplace_back(Token{CHARACTER, character, current_pos, row, line});
                    } else {
                        tokens.emplace_back(Token{match_to_prime_keyword(std::string(1, current_char)), std::string(1, current_char), current_pos, row, line});
                    }
                } else if (std::isalpha(current_char) || (std::isdigit(current_char) && std::isalpha(previous_char))) {
                    keyword += current_char;
                } else if (std::isdigit(current_char)) {
                    std::string number;
                    do {
                        number += current_char;
                        current_char = line[++i];
                    } while (std::isdigit(current_char));
                    tokens.emplace_back(Token{NUMBER, number, current_pos, row, line});
                    i--;
                } else {
                    prime_error::lexer::log_error(compiletime_start, 511, current_pos, row, current_char, line);
                    prime_error::lexer::note_error(compiletime_start, log_file, 511, current_pos, row, current_char, line);
                }
                previous_char = current_char;
            }
        }
        return tokens;
    }
};

/*
    class Parser {
        public:
        AST_node parse(std::vector<Token>* tokens) {
            int pos = 0;
            return parse_statements(tokens, pos);
        }
        private:
    };
*/

class Linker {
    //The linker will take the AST and link up headers and other files that are `liberated` from
};

class CPP {
    public:
    /*CPP() {


    }*/
};

int main(int argc, char** argv) {  
    log_usage(argv, argc);
    /*
        Lexer lex(line);
        Parser parse(lex);
    */
    std::string mode = "cpp", filename = "code.pri", line, call_command = "primec";// FOR TESTING STABILITY, REMOVE DEFAULT VALUES LATER
    /*
    std::getline(std::cin, call_command);
    std::stringstream ss(call_command);
    ss >> call_command >> mode >> filename;
    */
  
    time_t current_time;
    struct tm *time_info;
    char compile_time[20];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(compile_time, 20, "%Y-%m-%d %H:%M:%S", time_info);

    printf("Compiled at: %s\n", compile_time);

    // Start timing
    auto main_compiletime_start = std::chrono::high_resolution_clock::now();
    clock_t compiletime_start = clock();

    std::ifstream prime_file(filename);
    std::ofstream log_file("./logs/"+ filename + ".log", std::ios::app);

    Lexer lexer;
    std::future<std::vector<Token>> async_tokens = std::async(std::launch::async, [&lexer, &compiletime_start, &log_file, &prime_file](){
        return lexer.lex(compiletime_start, &log_file, &prime_file);
    });

    if(mode == "cpp") {
        std::ofstream cpp_file("./output/"+ filename + ".cpp");
        if(cpp_file.fail()) std::cerr << "ERROR: " << "cpp_file" << std::endl;
        //CPP cpp_instance();
    } else {
        //IF IT IS "execute" THE PROGRAM WILL JUST RUN LIKE USUAL
        std::cout << "\n~ Error: invalid compilation mode: " << mode << "\n";
    }

    //Parser parser;
    
    std::vector<Token> tokens = async_tokens.get();

    switch(prime_settings::debug_mode) {
        case true:
            ANSI_COLOR_OUTPUT(("Vector size: " + std::to_string(tokens.size()) + "\n\n"), "BrightGreen",{"Italic"});
            break;
        default: 
            std::cout << tokens.size() << "\n\n";
            break;
    }
    
    switch(prime_settings::debug_mode) {
        case true:
            for(int i = 0; i < tokens.size(); i++) {
                std::cout << "[" << tokens[i].type << ":" << tokens[i].value << "|" << tokens[i].position << "|" << tokens[i].row << "|" << tokens[i].line << "]" << std::endl << std::flush;
            }
            break;
        default: 
            break;
    }

    
    
    //parser.parse(&tokens/*, pos*/);
   
    //CPP FILE OUTPUT HANDLING
   
    prime_file.close();

    auto main_compiletime_stop = std::chrono::high_resolution_clock::now();

    auto main_compiletime_duration = std::chrono::duration_cast<std::chrono::milliseconds>(main_compiletime_stop - main_compiletime_start);
    
    std::ofstream COMPILETIME_TEST; // COMMENT OUT LATER
    COMPILETIME_TEST.open("async_compiler_core_compiletime_test.txt", std::ios::app);
    
    /*
    switch(prime_settings::debug_mode) {
        case true:
            ANSI_COLOR_OUTPUT(("Errors: "), "BrightRed",{}); std::cerr << prime_error::lexer::error_counter() << std::endl;
            ANSI_COLOR_OUTPUT(("Compile time: " + std::to_string(main_compiletime_duration.count()) + " ms\n"), "BrightBlue",{});
            break;
        default: 
            std::cout << "Errors: " << prime_error::lexer::error_counter() << "\n\n";
            std::cout << "Compile time: " << std::to_string(main_compiletime_duration.count()) + " ms\n";
            break;
    }
    */

    COMPILETIME_TEST << std::to_string(main_compiletime_duration.count()) << std::endl;
    COMPILETIME_TEST.close();

    if(prime_error::lexer::error_counter() > 0) exit(0);
    //ElSE:

    //EXECUTE PRIME CODE HERE
    return 0;
}
