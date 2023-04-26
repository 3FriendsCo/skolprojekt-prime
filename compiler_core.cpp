#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cctype>

#include "include/error.h"
#include "include/AST.h"
#include "include/Cpp.h"
#include "include/Token.h"
#include "include/color_lib.h"
#include "config/config.h"

static void log_usage(char** argv, int argc) { // Logs the usage of the program
    ANSI_COLOR_OUTPUT(("USAGE: [" + std::to_string(argc) + "] " + "<" + argv[0] + ">\n"), "BrightYellow",{"Italic","Bold","Underline"});
}

struct Token {
    Token_type type;
    std::string value;
    //META DATA:
    int position, row;
    std::string line;
};

/*

struct AST_node {
    AST_node_type type;
    int value;
    std::vector<AST_node*> children;
};

*/

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
                        tokens.emplace_back(Token{match_to_prime_keyword(std::string(1, current_char)), std::string(1, current_char), current_pos, row, line});
                        keyword.clear();
                    }
                    //tokens.emplace_back(Token{SPACE, " "}); PRETTY UNECESSARY
                    //If error, do error and "continue;"
                } else if (!std::isalnum(current_char)) {
                    if (std::isalpha(previous_char)) {
                        tokens.emplace_back(Token{match_to_prime_keyword(std::string(1, current_char)), std::string(1, current_char), current_pos, row, line});
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

class Parser {
    private:
    // UNKNOWN:
    inline AST_node UNKNOWN() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    // PRE-PROCESSORS:
    inline AST_node Seize() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Liberate() {
        AST_node pre_process_liberate;
        return pre_process_liberate;
    }
    inline AST_node Banish() {
        AST_node pre_process_banish;
        return pre_process_banish;
    }
    inline AST_node Force() {
        AST_node pre_process_force;
        return pre_process_force;
    }
    // 
    inline AST_node Global() {
        AST_node pre_process_global;
        return pre_process_global;
    }
    inline AST_node Static() {
        AST_node pre_process_static;
        return pre_process_static;
    }
    inline AST_node Const() {
        AST_node pre_process_const;
        return pre_process_const;
    }
    inline AST_node Main() {
        AST_node pre_process_main;
        return pre_process_main;
    }
    inline AST_node Function() {
        AST_node pre_process_function;
        return pre_process_function;
    }
    inline AST_node Return()
    {
        AST_node pre_process_return;
        return pre_process_return;
    }
    inline AST_node Using()
    {
        AST_node pre_process_using;
        return pre_process_using;
    }
    inline AST_node Enum()
    {
        AST_node pre_process_enum;
        return pre_process_enum;
    }
    inline AST_node Namespace()
    {
        AST_node pre_process_namespace;
        return pre_process_namespace;
    }
    inline AST_node Struct()
    {
        AST_node pre_process_struct;
        return pre_process_struct;
    }
    inline AST_node Class()
    {
        AST_node pre_process_class;
        return pre_process_class;
    }
    inline AST_node Unsigned()
    {
        AST_node pre_process_unsigned;
        return pre_process_unsigned;
    }
    inline AST_node Short()
    {
        AST_node pre_process_short;
        return pre_process_short;
    }
    inline AST_node Int()
    {
        AST_node pre_process_int;
        return pre_process_int;
    }
    inline AST_node Long()
    {
        AST_node pre_process_long;
        return pre_process_long;
    }
    inline AST_node Float()
    {
        AST_node pre_process_float;
        return pre_process_float;
    }
    inline AST_node Double()
    {
        AST_node pre_process_double;
        return pre_process_double;
    }
    inline AST_node Boolean()
    {
        AST_node pre_process_boolean;
        return pre_process_boolean;
    }
    inline AST_node Char()
    {
        AST_node pre_process_char;
        return pre_process_char;
    }
    inline AST_node String()
    {
        AST_node pre_process_string;
        return pre_process_string;
    }
    inline AST_node If()
    {
        AST_node pre_process_if;
        return pre_process_if;
    }
    inline AST_node Else()
    {
        AST_node pre_process_else;
        return pre_process_else;
    }
    inline AST_node Continue()
    {
        AST_node pre_process_continue;
        return pre_process_continue;
    }
    inline AST_node Break()
    {
        AST_node pre_process_break;
        return pre_process_break;
    }
    inline AST_node While()
    {
        AST_node pre_process_while;
        return pre_process_while;
    }
    inline AST_node Loop()
    {
        AST_node pre_process_loop;
        return pre_process_loop;
    }
    inline AST_node For()
    {
        AST_node pre_process_for;
        return pre_process_for;
    }
    inline AST_node Switch()
    {
        AST_node pre_process_switch;
        return pre_process_switch;
    }

    inline AST_node Basic_Namespace()
    {
        AST_node pre_process_basic_namespace;
        return pre_process_basic_namespace;
    }
    inline AST_node Log()
    {
        AST_node pre_process_log;
        return pre_process_log;
    }
    inline AST_node Formatted_Log()
    {
        AST_node pre_process_formatted_log;
        return pre_process_formatted_log;
    }
    inline AST_node Read()
    {
        AST_node pre_process_read;
        return pre_process_read;
    }
    inline AST_node Formatted_Read()
    {
        AST_node pre_process_formatted_read;
        return pre_process_formatted_read;
    }
    inline AST_node Write()
    {
        AST_node pre_process_write;
        return pre_process_write;
    }
    inline AST_node Formatted_Write()
    {
        AST_node pre_process_formatted_write;
        return pre_process_formatted_write;
    }
    // NOTE (MISSING)
    // FILE_TOKEN (MISSING)
    inline AST_node Dot()
    {
        AST_node pre_process_dot;
        return pre_process_dot;
    }
    inline AST_node Comma()
    {
        AST_node pre_process_comma;
        return pre_process_comma;
    }
    inline AST_node Colon()
    {
        AST_node pre_process_colon;
        return pre_process_colon;
    }
    inline AST_node Semicolon()
    {
        AST_node pre_process_semicolon;
        return pre_process_semicolon;
    }
    inline AST_node Questionmark()
    {
        AST_node pre_process_questionmark;
        return pre_process_questionmark;
    }

    void expects() {
        //expects the next token to be a certain type
    }
    
    public:
    std::vector<AST_node> parse(std::vector<Token>& tokens) {
        std::vector<AST_node> AST;
        for(int i = 0; i < tokens.size(); i++) {
            switch(tokens[i].type) {
                case SEIZE: Seize(); break;
                case LIBERATE: Liberate(); break;
                case BANISH: Banish(); break;
              //case FORCE: force(); break;
                case GLOBAL: Global(); break;
                case STATIC: Static(); break;
                case CONST: Const(); break;
                case MAIN: Main(); break;
                case FUNCTION: Function(); break;
                case RETURN: Return(); break;
                case USING: Using(); break;
                case ENUM: Enum(); break;
                case NAMESPACE: Namespace(); break;
                case STRUCT: Struct(); break;
                case CLASS: Class(); break;
                case UNSIGNED: Unsigned(); break;
                case SHORT: Short(); break;
                case INT: Int(); break;
                case LONG: Long(); break;
                case FLOAT: Float(); break;
                case DOUBLE: Double(); break;
                case BOOLEAN: Boolean(); break;
                case CHAR: Char(); break;
                case STRING: String(); break;
                case IF: If(); break;
                case ELSE: Else(); break;
                case CONTINUE: Continue(); break;
                case BREAK: Break(); break;
                case WHILE: While(); break;
                case LOOP: Loop(); break;
                case FOR: For(); break;
                case SWITCH: Switch(); break;
                
                case BASIC_NAMESPACE: Basic_Namespace(); break;
                case LOG: Log(); break;
                case FORMATTED_LOG: Formatted_Log(); break;
                case READ: Read(); break;
                case FORMATTED_READ: Formatted_Read(); break;
                case WRITE: Write(); break;
                case FORMATTED_WRITE: Formatted_Write(); break;
              //case NOTE: Note(); break;
              //case FILE_TOKEN: File();
                case DOT: Dot(); break;
                case COMMA: Comma(); break;
                case COLON: Colon(); break;
                case SEMICOLON: Semicolon(); break;
                case QUESTIONMARK: Questionmark(); break;

                default: UNKNOWN(); break;
            }
        }
        return AST;
    }
};

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

    if(mode == "cpp") {
        std::ofstream cpp_file("./output/"+ filename + ".cpp");
        if(cpp_file.fail()) std::cerr << "ERROR: " << "cpp_file" << std::endl;
        //CPP cpp_instance();
    } else {
        //IF IT IS "execute" THE PROGRAM WILL JUST RUN LIKE USUAL
        std::cout << "\n~ Error: invalid compilation mode: " << mode << "\n";
    }

    Lexer lexer;
    //Parser parser
    std::vector<Token> tokens = lexer.lex(compiletime_start, &log_file, &prime_file);
    
    //prime_file.close(); // Deallocate memory
    
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
   
    log_file.close();

    auto main_compiletime_stop = std::chrono::high_resolution_clock::now();

    auto main_compiletime_duration = std::chrono::duration_cast<std::chrono::milliseconds>(main_compiletime_stop - main_compiletime_start);
    
    std::ofstream COMPILETIME_TEST; // COMMENT OUT LATER
    COMPILETIME_TEST.open("compiler_core_compiletime_test.txt", std::ios::app);
    
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
