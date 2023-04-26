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
#include "include/Cpp.h"
#include "include/Token.h"
#include "include/color_lib.h"
#include "config/config.h"
#include "include/AST.h"

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
    void expects() {
        //expects the next token to be a certain type
    }
    
    public:
    std::vector<AST_node> parse(std::vector<Token>& tokens) {
        std::vector<AST_node> AST;
        for(int i = 0; i < tokens.size(); i++) {
            switch(tokens[i].type) {
                case SEIZE: Pre_processor::Seize(); break;
                case LIBERATE: Pre_processor::Liberate(); break;
                case BANISH: Pre_processor::Banish(); break;
              //case FORCE: Pre_processor::force(); break;
                case GLOBAL: Attribute::Global(); break;
                case STATIC: Attribute::Static(); break;
                case CONST: Attribute::Const(); break;
                case MAIN: Function::Main(); break;
                case FUNCTION: Function::Function(); break;
                case RETURN: Function::Return(); break;
                case USING: Scope::Using(); break;
                case ENUM: Scope::Enum(); Complex_type::Enum(); break;
                case NAMESPACE: Scope::Namespace(); break;
                case STRUCT: Complex_type::Struct(); break;
                case CLASS: Complex_type::Class(); break;
                case UNSIGNED: Attribute::Unsigned(); break;
                case SHORT: Primitive_type::Numeric_type::Short(); break;
                case INT: Primitive_type::Numeric_type::Int(); break;
                case LONG: Primitive_type::Numeric_type::Long(); break;
                case FLOAT: Primitive_type::Numeric_type::Float(); break;
                case DOUBLE: Primitive_type::Numeric_type::Double(); break;
                case BOOLEAN: Primitive_type::Boolean(); break;
                case CHAR: Primitive_type::Char(); break;
                case STRING: Nonprimitive_type::String(); break;
                case IF: Conditional_statement::If(); break;
                case ELSE: Conditional_statement::Else(); break;
                case CONTINUE: Control_flow_statement::Continue(); break;
                case BREAK: Control_flow_statement::Break(); break;
                case WHILE: Loop::While(); break;
                case LOOP: Loop::Loop(); break;
                case FOR: Loop::For(); break;
                case SWITCH: Conditional_statement::Switch(); break;
                
                case BASIC_NAMESPACE: Native_namespace::Basic_Namespace(); break;
                case LOG: IO::Log(); break;
                case FORMATTED_LOG: IO::Formatted_Log(); break;
                case READ: IO::Read(); break;
                case FORMATTED_READ: IO::Formatted_Read(); break;
                case WRITE: IO::Write(); break;
                case FORMATTED_WRITE: IO::Formatted_Write(); break;
              //case NOTE: Note(); break;
              //case FILE_TOKEN: File();
                case DOT: Symbol::Dot(); break;
                case COMMA: Symbol::Comma(); break;
                case COLON: Symbol::Colon(); break;
                case SEMICOLON: Symbol::Semicolon(); break;
                case QUESTIONMARK: Symbol::Questionmark(); break;
                case EXCLAMATIONPOINT: Symbol::Exclamationpoint(); break;
                case SINGLE_QOUTE: Symbol::Single_Qoute(); break;
                case DOUBLE_QOUTE: Symbol::Double_Qoute(); break;
                case L_PAREN: Symbol::Left_Parenthesis(); break;
                case R_PAREN: Symbol::Right_Parenthesis(); break;
                case L_CURLBRACKET: Symbol::Left_Curlybracket(); break;
                case R_CURLBRACKET: Symbol::Right_Curlybracket(); break;
                case L_BRACKET: Symbol::Left_Bracket(); break;
                case R_BRACKET: Symbol::Right_Bracket(); break;
                case LINE: Symbol::Line(); break;
                case HASH: Symbol::Hash(); break;
                case AT_S: Symbol::At_Symbol(); break;
                case DOLLAR: Symbol::Dollar(); break;
                case REFERENCE_S: Symbol::Reference_Symbol(); break;
                case PROCENT_S: Symbol::Procent_Symbol(); break;
                case AND_S: Symbol::And_Symbol(); break;
                case UNDERLINE: Symbol::Underline(); break;
                case B_SLASH: Symbol::Back_Slash(); break;
                case BACKTICK: Symbol::Backtick(); break;
                case CIRCUMFLEX: Symbol::Circumflex(); break;
                case TILDE: Symbol::Tilde(); break;
                case SECTION_S: Symbol::Section_Symbol(); break;
                case PLUS: Symbol::Plus(); break;
                case MINUS: Symbol::Minus(); break;
                case ASTRISK: Symbol::Astrisk(); break;
                case F_SLASH: Symbol::Forward_Slash(); break;
                case LESS_THAN: Symbol::Less_Than(); break;
                case GREATER_THAN: Symbol::Greater_Than(); break;

                default: Unknown::Unknown(); break;
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
