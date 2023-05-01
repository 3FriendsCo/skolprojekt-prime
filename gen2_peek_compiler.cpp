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
        if(prime_file) {
            if(prime_file.peek() == EOF) {
                std::cerr << "Empty compilable" << "\n" << std::flush;
                exit(1);
            }
            while(prime_file.peek() != EOF) {
                if(isspace(prime_file.peek())) {
                    current_char = prime_file.get();
                } else if(isdigit(prime_file.peek())) {

                } else if(isalpha(prime_file.peek())) {

                } else if(isascii(prime_file.peek())) {
                    
                } else {
                    //INVALID CHARACTER # UNSUPPORTED CHARACTER
                }
            }
        } else {
            //CONNECT TO "error.h" library later
            std::cerr << "Could not open compilable\n";
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
    token get_token(int index, std::shared_ptr<std::vector<token>> tokens) { 
        token this_token = (*tokens)[index];
        return this_token;
    }
    public:
    std::shared_ptr<std::vector<AST_node*>> parse(std::shared_ptr<std::vector<token>> tokens) {
        auto AST = std::make_shared<std::vector<AST_node*>>();
        int index;
        get_token(index, tokens);
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
    std::string filename = "code.pri";
    //std::cin >> filename;
    std::ifstream prime_file; prime_file.open(filename);
    std::unique_ptr<Lexer> lexer(new Lexer(prime_file));
    //Parser parser;
    //std::shared_ptr<std::vector<AST_node*>> AST = parser.parse(lexer->tokens);

    for(token& i:*lexer->tokens) {
        std::cout << i.type << ":" << i.value << "\n" << std::flush;
    }

    auto main_compiletime_stop = std::chrono::high_resolution_clock::now();
    auto main_compiletime_duration = std::chrono::duration_cast<std::chrono::milliseconds>(main_compiletime_stop - main_compiletime_start);
    std::cerr << std::to_string(main_compiletime_duration.count()) << "\n" << std::flush;
    return 0;
}