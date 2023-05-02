#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <sstream>
#include <cctype>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <memory>

enum token_type {
    ERROR = -1,
    NUMBER = 0,
    STR_LITERAL = 1,
    CHAR_LITERAL = 2,
    // KEYWORDS:

    // SYMBOLS:
    F_SLASH,
    ASTRIKS,
// Logical Operators:
    // Comparison Operators:
    EQUALS,
    EQUAL_TO,
    IDENTICAL_TO,

    NOT_EQUAL_TO,
    NOT_IDENTICAL_TO,

    GREATER_THAN,
    GREATER_THAN_OR_EQUAL_TO,
    GREATER_THAN_OR_IDENTICAL_TO,
    
    LESS_THAN,
    LESS_THAN_OR_EQUAL_TO,
    LESS_THAN_OR_IDENTICAL_TO,
};

struct Instructions {
    // Registers
    // push/pop
    // ADD, SUB, MUL, DIV, MOD
};

struct token {
    token_type type;
    std::string value;
};

class Lexer {
    std::shared_ptr<std::vector<token>> lex(std::ifstream& p_file) {
        int current_pos = 0, row = 0;
        char current_char = '\0', prev_char = '\0';
        std::shared_ptr<std::vector<token>> tokens = std::make_shared<std::vector<token>>();
        std::string keyword;
        if(p_file.is_open()) {
            if(p_file.peek() == EOF) {
                std::cerr << "Empty compilable (file)" << "\n" << std::flush;
                exit(1);
            }
            while(p_file.peek() != EOF) {
                if(isspace(p_file.peek())) {

                } else if(isdigit(p_file.peek())) {
                    
                } else if(isdigit(p_file.peek())) {

                } else if(isalpha(p_file.peek())) {

                } else if(ispunct(p_file.peek())) {
                    current_char = p_file.get();
                    switch(current_char) {
                        case '+': switch(p_file.peek()) {
                            default: current_char = p_file.peek(); break; // ignore, lex as: '+'
                            case '=': current_char = p_file.peek();break; // logical operator: "+="
                            case ' ': current_char = p_file.peek();break; // ignore, lex as: '+'
                            case '+': current_char = p_file.peek();break; // incremental operator: "++"
                        }
                        break;
                        case '-': switch(p_file.peek()) {
                            default: break;
                            case '=': break;
                            case ' ': break;
                            case '-': break;
                        }
                        break;
                        case '*': switch(p_file.peek()) {
                            default: break;
                            case '=': break;
                            case ' ': break;
                            case '+': break;
                        } 
                        break;
                        case '/':  switch(p_file.peek()) {
                            default: break;
                            case '=': break;
                            case ' ': break;
                            case '+': break;
                        }
                        break; // It is a logical operator
                        case '%': break; // It is a logical operator
                        case '^': break; // It is a logical operator
                        case '_': 
                    }
                } else if(isascii(p_file.peek())) {
                    if(isprint(p_file.peek())) {
                        tokens->emplace_back(token{NUMBER,"DAS"});
                    } else {
                        // CHARACTER CANNOT BE PRINTED!
                        // LIBERATE CORRECT LOCALE
                    }
                } else {
                    //INVALID CHARACTER
                }
            }
        } else {
            //CONNECT TO "error.h" library later
            std::cerr << "Could not open compilable (file)\n";
            std::cerr << "\t- Compilable not found, Compilable does not exist\n";
            std::cerr << "\t- Compilable filepath might be wrong, check it\n";
            exit(1);
        }
        p_file.close();
        return tokens;
    }
    public:
    std::shared_ptr<std::vector<token>> tokens;
    Lexer(std::ifstream& p_file): tokens(lex(p_file)){
        std::cout << "LEXED:\n";
    }
};

enum class Node_type {

};

struct AST_node {
    Node_type type;
    int token_type;
    std::string value;
    std::vector<AST_node*> children;
};

class Parser {
    public:
    std::shared_ptr<std::vector<AST_node*>> parse(std::shared_ptr<std::vector<token>> tokens) {
        auto AST = std::make_shared<std::vector<AST_node*>>();
        return AST;
    }
};

class Semantic_Analyzer {
    public:
    void analyze(std::vector<AST_node*> tree) {

    }
    private:
    void search() {
        std::unordered_map<std::string, AST_node*> semantic_standard;
    }
};

class Code_Generator{
    std::unordered_map<std::string,std::string> x86_instructions {
        {" "," "},
        {" "," "},
        {" "," "}
    };

    void optimizer(){
        
    }
};

class Linker {

};

int main(int argc, char **argv) {
    if(argc < 2) {std::cerr << "USAGE: " << argv[0] << "\n" << std::flush;/*exit(1);*/}
    auto main_compiletime_start = std::chrono::high_resolution_clock::now();

    // Code goes here
    std::ifstream p_file("code.pri");
    std::unique_ptr<Lexer> lexer(new Lexer(p_file));
    Parser parser;
    std::shared_ptr<std::vector<AST_node*>> AST = parser.parse(lexer->tokens);
    /*
    for(token& i:*lexer.tokens) {
        std::cout << i.type << ":" << i.value << "\n" << std::flush;
    }
    */
    auto main_compiletime_stop = std::chrono::high_resolution_clock::now();
    auto main_compiletime_duration = std::chrono::duration_cast<std::chrono::milliseconds>(main_compiletime_stop - main_compiletime_start);
    std::cerr << std::to_string(main_compiletime_duration.count()) << "\n" << std::flush;
    return 0;
}