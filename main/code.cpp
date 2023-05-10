#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <chrono>

#include "../include/error.h"
#include "../main/include/node.h"

enum token_type {

};

struct token {
    token_type type;
    std::string value;
};

class AST_node {
    public:
    virtual ~AST_node() = default;
};

class Lexer
{
public:
    std::vector<token> tokens;
    Lexer(std::ifstream *input)
    {
        tokens = lex(input);
    }
    ~Lexer()
    {
        
    }

private:
    std::vector<token> lex(std::ifstream *input)
    {
        if (!input->is_open())
        {
            // ERROR!
        }
        char current_char = '\0', char_literal = '\0';
        int deci_count = 0, current_pos = 1, current_row = 1;
        std::vector<token> tokens;
        std::string keyword = "", num_literal = "", str_literal = "";

        while (input->peek() != EOF)
        {
            current_char = input->get();
            if (current_char == '\n')
            { // New line

            }
            else if (current_char == ' ')
            { // Space
                
            }
            else if (isdigit(current_char))
            { // Digit
                while (isdigit(current_char) || current_char == '.')
                {
                    num_literal += current_char;
                    current_char = input->get();
                }
                switch (deci_count)
                {
                case 0: /* INT */
                    tokens.emplace_back(token{});
                    break;
                case 1: /* FLOAT/DOUBLE/etc */
                    tokens.emplace_back(token{});
                    break;
                default: /* OMNI_LITERAL */
                    tokens.emplace_back(token{});
                    break;
                }
                num_literal.clear();
                deci_count = 0;
            }
            else if (isalpha(current_char))
            {
                while (isalpha(current_char) || isdigit(current_char) || current_char == '_')
                {
                    keyword += current_char;
                    current_char = input->get();
                }
                tokens.emplace_back(token{});
                keyword.clear();
            }
            else if (ispunct(current_char))
            {
                switch (current_char)
                {
                case '\"': // str_literal
                    while (current_char != '\"')
                    {
                        str_literal += current_char;
                        current_char = input->get();
                        if (current_char == '\\')
                        {
                            str_literal += current_char;
                            current_char = input->get();
                            str_literal += current_char;
                        }
                    }
                    tokens.emplace_back(token{});
                    str_literal.clear();
                    break;
                case '\'':
                    // char_literal
                    while (current_char != '\'')
                    {
                        str_literal += current_char;
                        current_char = input->get();
                        if (current_char == '\\')
                        {
                            str_literal += current_char;
                            current_char = input->get();
                            str_literal += current_char;
                        }
                    }
                    tokens.emplace_back(token{});
                    str_literal.clear();
                    break;
                case '\\':
                    break;
                }
                tokens.emplace_back(token{});
            }
            else
            {
                // ERROR!
            }
        }
    }
};

class Parser {
    public:
    Parser(std::vector<token> &tokens) {
        std::vector<AST_node> AST = parse(tokens);
    }
    
    ~Parser() {

    }
    private:
    void getToken(std::vector<token> *tokens) {

    }
    std::vector<AST_node> parse(std::vector<token> &tokens) {
        std::vector<AST_node> AST;
        for(token& i:tokens) {
            switch(i.type) {
                case 0: break;
                case 1: break;
                case 2: break;
                default: break;
            }
        }
        return AST;
    }
};

int main(int argc, char** argv) {
    std::cout << "Usage: "
              << argv[0]
              << std::endl
              << std::endl;
    std::string filename = "code.pri";
    // std::cin >> filename;
    std::cout << "$$$$$$$\\            $$\\\n"
              << "$$  __$$\\           \\__|\n"
              << "$$ |  $$ | $$$$$$\\  $$\\ $$$$$$\\$$$$\\   $$$$$$\\\n"
              << "$$$$$$$  |$$  __$$\\ $$ |$$  _$$  _$$\\ $$  __$$\\\n"
              << "$$  ____/ $$ |  \\__|$$ |$$ / $$ / $$ |$$$$$$$$ |\n"
              << "$$ |      $$ |      $$ |$$ | $$ | $$ |$$   ____|\n"
              << "$$ |      $$ |      $$ |$$ | $$ | $$ |\\$$$$$$$\\\n"
              << "\\__|      \\__|      \\__|\\__| \\__| \\__| \\_______|\n\n";

    auto cts = std::chrono::high_resolution_clock::now();
    std::ifstream pfile;
    pfile.open(filename);
    Lexer lexer(&pfile);
    Parser parser(lexer.tokens);
    auto cte = std::chrono::high_resolution_clock::now();
    auto ct = std::chrono::duration_cast<std::chrono::milliseconds>(cte - cts);

    return 0;
}