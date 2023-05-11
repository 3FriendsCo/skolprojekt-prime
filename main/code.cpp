#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <chrono>

// #include "../include/error.h"
#include "../main/include/node.h"

<<<<<<< HEAD:main/core.cpp
namespace Token {
    enum type   {
        PROGRAM = -4,
        END_OF_STATEMENT = -3,
        END_OF_LINE = -2,
        END_OF_FILE = -1,
        UNKNOWN, // For testing
        UNKNOWN_SYMBOL,

        INT_LITERAL,
        DECI_LITERAL,
        OMNI_LITERAL,
    };

    struct token
    {
        int keyword_row, keyword_pos;
        type _type;
        std::string value;
    };
=======
enum token_type {

};

struct token {
    token_type type;
    std::string value;
>>>>>>> e17ec5651b43b7ad83b9660336f09d712037329e:main/code.cpp
};

class AST_node {
    public:
    virtual ~AST_node() = default;
};

class Lexer
{
public:
    std::vector<Token::token> tokens;
    Lexer(std::ifstream *input)
    {
        tokens = lex(input);
    }
    ~Lexer()
    {
        
    }

private:
    std::vector<Token::token> lex(std::ifstream *input)
    {
        if (!input->is_open())
        {
            // ERROR!
        }
        char current_char = '\0', char_literal = '\0';
        int deci_count = 0, current_pos = 1, current_row = 1;
        std::vector<Token::token> tokens;
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
                    tokens.emplace_back(Token::token{});
                    break;
                case 1: /* FLOAT/DOUBLE/etc */
                    tokens.emplace_back(Token::token{});
                    break;
                default: /* OMNI_LITERAL */
                    tokens.emplace_back(Token::token{});
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
                tokens.emplace_back(Token::token{});
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
                    tokens.emplace_back(Token::token{});
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
                    tokens.emplace_back(Token::token{});
                    str_literal.clear();
                    break;
                case '\\':
                    break;
                }
                tokens.emplace_back(Token::token{});
            }
            else
            {
                // ERROR!
            }
        }
        return tokens;
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
<<<<<<< HEAD:main/core.cpp
    std::vector<Node::node*> parse(std::vector<Token::token>& tokens) {
        std::vector<Node::node*> AST;
        for(Token::token i: tokens) {
            switch(i._type) {
                case -4:// Program
                    
                    break;
                case -3:// End of statement

                    break; 
                case -2:// End of line

                    break; 
                case -1:// End of file 

                    break;
                case 0:// Unknown
    
                    break;
                case 1:// Unknown Symbol

                    break;
=======
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
>>>>>>> e17ec5651b43b7ad83b9660336f09d712037329e:main/code.cpp
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
<<<<<<< HEAD:main/core.cpp
    //Parser parser;
    auto cte = std::chrono::high_resolution_clock::now();
    auto ct = std::chrono::duration_cast<std::chrono::milliseconds>(cte - cts);
    std::cerr << "Compiletime: "
              << ct.count()
              << std::endl
              << std::endl
              << std::flush;

    for (Token::token iterator : lexer.tokens)
    {
        std::cout << iterator.keyword_row << "|" << iterator.keyword_pos << "|" << iterator.value << ":" << iterator._type << std::endl;
    }

    std::cout << "Token list size: " << lexer.tokens.size();
=======
    Parser parser(lexer.tokens);
    auto cte = std::chrono::high_resolution_clock::now();
    auto ct = std::chrono::duration_cast<std::chrono::milliseconds>(cte - cts);
>>>>>>> e17ec5651b43b7ad83b9660336f09d712037329e:main/code.cpp

    return 0;
}