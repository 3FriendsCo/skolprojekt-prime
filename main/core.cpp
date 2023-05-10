#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

#include "../include/error.h"
#include "../main/include/node.h"

enum type
{
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

enum AST_type {

};

struct token
{
    int keyword_row, keyword_pos;
    type _type;
    std::string value;
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

class Parser
{
    public:
    Parser() {

    }
    private:
    token getToken()
    {
        token _token;
        return _token;
    }

    std::vector<AST_node*> parse() {
        std::vector<AST_node*> AST;
        return AST;
    }
};

int main(int argc, char **argv)
{
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
    Parser parser;
    auto cte = std::chrono::high_resolution_clock::now();
    auto ct = std::chrono::duration_cast<std::chrono::milliseconds>(cte - cts);
    std::cerr << "Compiletime: "
              << ct.count()
              << std::endl
              << std::endl
              << std::flush;

    for (token iterator : lexer.tokens)
    {
        std::cout << iterator.keyword_row << "|" << iterator.keyword_pos << "|" << iterator.value << ":" << iterator._type << std::endl;
    }

    std::cout << "Token list size: " << lexer.tokens.size();

    return 0;
}