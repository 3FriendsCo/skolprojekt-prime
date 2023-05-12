#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <map>

// #include "../include/error.h"
#include "../include/node.h"

// g++ -O3 main.cpp -o main
// -03 will optimize the compiled code

class Preprocessor
{
public:
    Preprocessor(std::ifstream *p_pfile)
    {
        if (!p_pfile->is_open())
        {
            // ERROR!
            exit(1);
        }
        char current_char = '\0';
        std::string buffer = "\0";
        while (p_pfile->peek() != EOF)
        {
            current_char = p_pfile->get();
        }
    }
};

namespace Token
{
    enum type
    {
        PROGRAM = -4,
        END_OF_STATEMENT = -3,
        END_OF_LINE = -2,
        END_OF_FILE = -1,
        // UNKNOWN:
        UNKNOWN, // For testing
        UNKNOWN_SYMBOL,
        // PREPROCESSES:
        SEIZE,
        BANISH,
        LIBERATE,
        FORCE,
        // FUNCTION:
        MAIN,
        FUNCTION,
        // LITERALS:
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
                    tokens.emplace_back(std::move(Token::token{0, 0, Token::UNKNOWN, "a"}));
                    break;
                case 1: /* FLOAT/DOUBLE/etc */
                    tokens.emplace_back(std::move(Token::token{0, 0, Token::UNKNOWN, "a"}));
                    break;
                default: /* OMNI_LITERAL */
                    tokens.emplace_back(std::move(Token::token{0, 0, Token::UNKNOWN, "a"}));
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
                tokens.emplace_back(std::move(Token::token{0, 0, Token::UNKNOWN, "a"}));
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
                    tokens.emplace_back(std::move(Token::token{0, 0, Token::UNKNOWN, "a"}));
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
                    tokens.emplace_back(std::move(Token::token{0, 0, Token::UNKNOWN, "a"}));
                    str_literal.clear();
                    break;
                case '\\':
                    break;
                }
                tokens.emplace_back(std::move(Token::token{0, 0, Token::UNKNOWN, "a"}));
            }
            else
            {
                // ERROR!
            }
        }
        return tokens;
    }
};

class Parser
{
public:
    std::vector<Node::node *> AST;
    Parser(std::vector<Token::token> *tokens)
    {
        parse(tokens);
    }

private:
    void parse(std::vector<Token::token> *tokens)
    {
        for (Token::token i : *tokens)
        {
            switch (i._type)
            {
            case Token::MAIN:
                break;
            }
        }
    }
};

std::map<Node::type, std::string> nodeToFile{
    {Node::FUNCTION_DEFINITION, "../include/assembly/function_definition.asm"},
    {Node::STR_DEFINITION, "../include/assembly/str_definition.asm"},
    {Node::CHAR_DEFINITION, "../include/assembly/char_definition.asm"},
    {Node::INT_DEFINITION, "../include/assembly/int_definition.asm"},
    {Node::FLOAT_DEFINITION, "../include/assembly/float_definition.asm"},
    {Node::DOUBLE_DEFINITION, "../include/assembly/double_definition.asm"},
    {Node::BOOL_DEFINITION, "../include/assembly/bool_definition.asm"}};

class Generator
{
public:
    Generator(std::vector<Node::node *> *AST)
    {
        generate(AST);
    }

private:
    void generate(std::vector<Node::node *> *AST)
    {
        std::ofstream output_file;
        output_file.open("generated_assembly.asm");

        // Write the _begin.asm file first
        std::ifstream begin_file("../include/assembly/_begin.asm");
        if (begin_file.is_open())
        {
            std::string line;
            while (std::getline(begin_file, line))
            {
                output_file << line << std::endl;
            }
            begin_file.close();
        }
        else
        {
            std::cerr << "Failed to open file: ../include/assembly/_begin.asm" << std::endl;
        }

        for (auto node : *AST)
        {
            auto iter = nodeToFile.find(node->_type);
            if (iter != nodeToFile.end())
            {
                std::ifstream input_file(iter->second);
                if (input_file.is_open())
                {
                    std::string line;
                    while (std::getline(input_file, line))
                    {
                        output_file << line << std::endl;
                    }
                    input_file.close();
                }
                else
                {
                    std::cerr << "Failed to open file: " << iter->second << std::endl;
                }
            }
            else
            {
                std::cerr << "No file associated with node type: " << node->_type << std::endl;
            }
        }
        output_file.close();
    }
};

int main(int argc, char **argv)
{
    std::cout << "Usage: "
              << argv[0]
              << "\n\n";
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
    std::ifstream p_pfile;
    pfile.open(filename);
    p_pfile.open(filename);

    Preprocessor preprocessor(&p_pfile);
    Lexer lexer(&pfile);
    Parser parser(&lexer.tokens);
    Generator generator(&parser.AST);

    auto cte = std::chrono::high_resolution_clock::now();
    auto ct = std::chrono::duration_cast<std::chrono::milliseconds>(cte - cts);
    std::cerr << "Compiletime: "
              << ct.count()
              << " ms\n\n"
              << std::flush;

    for (Token::token iterator : lexer.tokens)
    {
        std::cout << iterator.keyword_row << "|" << iterator.keyword_pos << "|" << iterator.value << ":" << iterator._type << "\n"
                  << std::flush;
    }

    std::cout << "Token list size: " << lexer.tokens.size();

    return 0;
}