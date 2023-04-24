#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <sstream>
#include <chrono>

//#include "include/error.h"
#include "include/prime_ast.h"
#include "include/Cpp.h"
#include "include/Token.h"
#include "include/color_lib.h"

static void log_usage(char** argv, int argc/*, mode*/) { //Logs the usage of the program
    ANSI_COLOR_OUTPUT(("USAGE: [" + std::to_string(argc) + "] " + "<" + argv[0] + ">\n"), "BrightYellow",{"Italic","Bold","Underline"});
}

struct Token {
    Token_type type;
    std::string value;
};

struct AST_node {
    AST_node_type type;
    int value;
    std::vector<AST_node*> children;
};

Token_type match_to_prime_keyword(const std::string keyword);

class Lexer {
public:
    std::vector<Token> lex(std::ifstream* prime_file) {
        int current_pos;
        char current_char, previous_char = 0;
        std::vector<Token> tokens;
        std::string keyword, line;

        while (std::getline(*prime_file, line)) {
            line.push_back(' ');
            for (size_t i = 0; i < line.length(); i++) {
                current_pos = i;
                current_char = line[current_pos];

                if (std::isspace(current_char)) {
                    if (isalpha(previous_char)) {
                        tokens.emplace_back(Token{match_to_prime_keyword(keyword), keyword});
                        keyword.clear();
                    }
                    tokens.emplace_back(Token{SPACE, " "});
                } else if (!std::isalnum(current_char)) {
                    if (std::isalpha(previous_char)) {
                        tokens.emplace_back(Token{match_to_prime_keyword(keyword), keyword});
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
                        tokens.emplace_back(Token{MESSAGE, message});

                    } else if (current_char == '\'') {
                        std::string character;
                        character += current_char;
                        while (++i < line.length() && (current_char = line[i]) != '\'') {
                            character += current_char;
                        }
                        character += current_char;
                        tokens.emplace_back(Token{CHARACTER, character});
                    } else {
                        tokens.emplace_back(Token{match_to_prime_keyword(std::string(1, current_char)), std::string(1, current_char)});
                    }
                } else if (std::isalpha(current_char) || (std::isdigit(current_char) && std::isalpha(previous_char))) {
                    keyword += current_char;
                } else if (std::isdigit(current_char)) {
                    std::string number;
                    do {
                        number += current_char;
                        current_char = line[++i];
                    } while (std::isdigit(current_char));
                    tokens.emplace_back(Token{NUMBER, number});
                    i--;
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
    std::string mode, filename, line, call_command;
    std::getline(std::cin, call_command);
    std::stringstream ss(call_command);
    ss >> call_command >> mode >> filename;

    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream prime_file(filename);
    std::ofstream log_file("./logs/"+ filename + ".log");

    if(mode == "cpp") {
        std::ofstream cpp_file("./output/"+ filename + ".cpp");
        if(cpp_file.fail()) std::cerr << "ERROR: " << "cpp_file" << std::endl;
        //CPP cpp_instance();
   
    } else {
        //IF IT IS "execute" THE PROGRAM WILL JUST RUN LIKE USUAL
        std::cout << "\n~ Error: invalid compilation mode: " << mode << "\n";
    }

    Lexer lexer;
    //Parser parser;

    std::vector<Token> tokens = lexer.lex(&prime_file);

    //primec_err::log_error("ERROR! Just a friendly error, nothing wrong with your code ;)", "BrightRed");
    
    ANSI_COLOR_OUTPUT(("Vector size: " + std::to_string(tokens.size()) + "\n\n"), "BrightGreen",{"Italic"});
    
    /*
    
    for(int i = 0; i < tokens.size(); i++) {
        std::cout << "[" << tokens[i].type << "," << tokens[i].value <<"]" << std::endl << std::flush;
    }

    */
    
    //parser.parse(&tokens/*, pos*/);
   
    //CPP FILE OUTPUT HANDLING
   
    prime_file.close();

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    ANSI_COLOR_OUTPUT(("Compile time: " + std::to_string(duration.count()) + " ms\n"), "BrightBlue",{});

    //EXECUTE PRIME CODE HERE

    return 0;
}
