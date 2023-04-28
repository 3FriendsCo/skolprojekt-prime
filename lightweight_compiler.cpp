#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <vector>
#include <unordered_map>

enum class token_type {
    NUMBER = 0
};

struct Instructions {

};

struct token {
    token_type type;
    std::wstring value;
};

class Lexer {
    public:
    std::vector<token> lex(std::ifstream& prime_file) {
        std::vector<token> tokens;
        wchar_t current_char = prime_file.peek();
        wchar_t previous_char = current_char;
        std::wstring keyword;
        if(prime_file.is_open()) {
            while(current_char != EOF) {
                if(isspace(current_char)) {// current character is a space
                    continue;
                } else if(iswalpha(current_char)) {// current character is a character

                } else if(isdigit) {// current_char is a digit
                    if(isalpha(previous_char)) {
                        keyword += current_char;
                    } else {
                        std::wstring number(current_char, 1);
                        while(isdigit(current_char)) {
                            number += current_char;
                            current_char = prime_file.get();
                        }
                        tokens.emplace_back(token{NUMBER, number});
                    }
                } else {// current_char is a symbol
                    if(current_char == '\"') {

                    } else if() {

                    } else {

                    }
                }
                previous_char = current_char;
                current_char = prime_file.get();
            }
        } else {
            //CONNECT TO "error.h" library later
            std::cerr << "Could not open compile of intrest file\n";
            std::cerr << "\t- File not found, file does not exist\n";
            exit(1);
        }
        return tokens;
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
    std::vector<AST_node*> parse() {

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
    if(argc < 2) {std::cerr << "USAGE: " << argv[0] << std::endl << std::flush;/*exit(1);*/}
    auto main_compiletime_start = std::chrono::high_resolution_clock::now();

    // Code goes here
    std::ifstream prime_file("code.pri");
    Lexer lexer;
    lexer.lex(prime_file);

    auto main_compiletime_stop = std::chrono::high_resolution_clock::now();
    auto main_compiletime_duration = std::chrono::duration_cast<std::chrono::milliseconds>(main_compiletime_stop - main_compiletime_start);
    std::cerr << std::to_string(main_compiletime_duration.count()) << std::endl << std::flush;
    return 0;
}