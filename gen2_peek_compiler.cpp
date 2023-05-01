#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <sstream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <memory>

enum token_type {
    ERROR = -1,
    NUMBER = 0,
    STR_LITERAL = 1,
    CHAR_LITERAL = 2,
    //KEYWORDS:

    //SYMBOLS:
    F_SLASH,
    ASTRIKS
};

struct Instructions {

};

struct token {
    token_type type;
    std::string value;
};

class Lexer {
    std::shared_ptr<std::vector<token>> lex(std::ifstream& prime_file) {
        int current_pos = 0, row = 0;
        char current_char = '\0', prev_char = '\0';
        std::shared_ptr<std::vector<token>> tokens = std::make_shared<std::vector<token>>();
        std::string keyword;
        if(prime_file.is_open()) {
            if(prime_file.peek() == EOF) {
                std::cerr << "Empty compilable (file)" << "\n" << std::flush;
                exit(1);
            }
            while(prime_file.peek() != EOF) {
                if(isspace(prime_file.peek())) {// current character is a space
                    prime_file.ignore(1);
                    continue;
                } else if(isalpha(prime_file.peek())) {// current character is a character
                    current_char = prime_file.get();
                    while(isalnum(current_char)) {
                        keyword += current_char;
                        current_char = prime_file.get();
                    }
                    tokens->emplace_back(token{NUMBER,/*Call token type finder,*/ keyword});
                } else if(isdigit(prime_file.peek())) {// current_char is a digit
                    std::string number(1, current_char);
                    while(isdigit(current_char)) {
                        number += current_char;
                        current_char = prime_file.get();
                    }
                    tokens->emplace_back(token{NUMBER, number});
                } else {// current_char is a symbol
                    if(current_char == '\"') {
                        std::string message(current_char, 1);
                        while(current_char != '\"') {
                            current_char = prime_file.get();
                            if(prime_file.eof()) {
                                // Error: end of file reached before finding closing quotation mark
                                tokens->emplace_back(token{ERROR, "Unclosed string literal"});
                                return tokens;
                            }
                            if(current_char == '\\') {
                                message += current_char;
                                current_char = prime_file.get();
                            }
                            message += current_char;
                        }
                        tokens->emplace_back(token{STR_LITERAL, message});
                    } else if(current_char == '\'') {
                        std::string character(current_char, 1);
                        while(current_char != '\'') {
                            current_char = prime_file.get();
                            if(prime_file.eof()) {
                                // Error: end of file reached before finding closing quotation mark
                                tokens->emplace_back(token{ERROR, "Unclosed character literal"});
                                return tokens;
                            }
                            if(current_char == '\\') {
                                character += current_char;
                                current_char = prime_file.get();
                            }
                            character += current_char;
                        }
                            tokens->emplace_back(token{CHAR_LITERAL, character});
                    } else if(current_char == '/') {
                        if(prime_file.peek() == '/') { // it is a comment
                            prime_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore until end of line
                        } else if(prime_file.peek() == '*') { // it is a multiline-comment
                            prime_file.ignore(std::numeric_limits<std::streamsize>::max(), '*');
                            if(prime_file.get() == '/') {
                                current_char = prime_file.get();
                            } else {
                                tokens->emplace_back(token{ASTRIKS, std::string(current_char, 1)});
                            }
                        } else {
                            tokens->emplace_back(token{F_SLASH, std::string(current_char, 1)});
                        }
                    } else if(current_char == '+'||current_char == '-'||current_char == '='||current_char == '<'||current_char == '>'||current_char == '/'||current_char == '*'||current_char == '%') {
                        prev_char = current_char;
                        if(prime_file.peek() == '+'||prime_file.peek() == '-'||prime_file.peek() == '='||prime_file.peek() == '<'||prime_file.peek() == '>'||prime_file.peek() == '/'||prime_file.peek() == '*'||prime_file.peek() == '%') {
                            // This means that the keyword that is read is a logical operator and can be lexed as one
                            tokens->emplace_back(token{NUMBER/*match_prime_operator(current_char, prev_char)*/});
                        } else {
                            //Lex as the standalone symbol
                            tokens->emplace_back(token{NUMBER/*match_prime_keyword(current_char)*/, std::string(current_char,1)});
                        }
                    }
                }
                prev_char = current_char;
                current_char = prime_file.get();
            }
        } else {
            //CONNECT TO "error.h" library later
            std::cerr << "Could not open compilable (file)\n";
            std::cerr << "\t- Compilable not found, Compilable does not exist\n";
            std::cerr << "\t- Compilable filepath might be wrong, check it\n";
            exit(1);
        }
        prime_file.close();
        return tokens;
    }
    public:
    std::shared_ptr<std::vector<token>> tokens;
    Lexer(std::ifstream& prime_file): tokens(lex(prime_file)){
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
    std::ifstream prime_file("code.pri");
    std::unique_ptr<Lexer> lexer(new Lexer(prime_file));
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