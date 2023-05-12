#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <string>

#include "../include/node.h"

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

class Preprocessor
{
public:
    void process(std::ifstream *pfile, std::ifstream *p_pfile) {
       /* // Make sure the file is good to read.
        if (!pfile->good())
        {
            return;
        }

        // Get iterator pointing to the beginning of the file
        std::istreambuf_iterator<char> begin(*pfile);

        // Get end-of-stream iterator
        std::istreambuf_iterator<char> end;

        // Construct a string using the range provided by the
        // beginning and end-of-stream iterators.
        std::string buffer(begin, end);
        
        // prints the contents of the .pri file
        std::cout << buffer;

        // Add null terminator at the end
        buffer.push_back('\0');

        // Tokenization logic goes here
        */
    }
};

class Lexer
{
public:
    std::vector<Token::token> *tokens;

    void lex(std::ifstream *pfile)
    {
        // Make sure the file is good to read.
        if (!pfile->good())
        {
            return;
        }

        // Get iterator pointing to the beginning of the file
        std::istreambuf_iterator<char> begin(*pfile);

        // Get end-of-stream iterator
        std::istreambuf_iterator<char> end;

        // Construct a string using the range provided by the
        // beginning and end-of-stream iterators.
        std::string buffer(begin, end);
        
        // prints the contents of the .pri file
        std::cout << buffer;

        // Add null terminator at the end
        buffer.push_back('\0');

        // Tokenization logic goes here
        char current_char = '\0', char_literal = '\0';
        int deci_count = 0, current_pos = 1, current_row = 1;
        std::vector<Token::token> tokens;
        std::string keyword = "", num_literal = "", str_literal = "";

        for (int i = 0; i < buffer.length(); i++)
        {
            current_char = buffer[i];
            if (current_char == '\n')
            {
                continue;
                // New line
            }
            else if (current_char == ' ')
            { // Space
            }
            else if (isdigit(current_char))
            { // Digit
                while (isdigit(current_char) || current_char == '.')
                {
                    num_literal += current_char;
                    i++;
                    current_char = buffer[i];
                }
                switch (deci_count)
                {
                case 0: /* INT */
                    tokens.emplace_back(std::move(Token::token{0,0,Token::UNKNOWN,"Hej"}));
                    break;
                case 1: /* FLOAT/DOUBLE/etc */
                    tokens.emplace_back(std::move(Token::token{0,0,Token::UNKNOWN,"Hej"}));
                    break;
                default: /* OMNI_LITERAL */
                    tokens.emplace_back(std::move(Token::token{0,0,Token::UNKNOWN,"Hej"}));
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
                    i++;
                    current_char = buffer[i];
                }
                tokens.emplace_back(std::move(Token::token{0,0,Token::UNKNOWN,"Hej"}));
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
                        i++;
                        current_char = buffer[i];
                        if (current_char == '\\')
                        {
                            str_literal += current_char;
                            i++;
                            current_char = buffer[i];
                            str_literal += current_char;
                        }
                    }
                    tokens.emplace_back(std::move(Token::token{0,0,Token::UNKNOWN,"Hej"}));
                    str_literal.clear();
                    break;
                case '\'':
                    // char_literal
                    while (current_char != '\'')
                    {
                        str_literal += current_char;
                        i++;
                        current_char = buffer[i];
                        if (current_char == '\\')
                        {
                            str_literal += current_char;
                            i++;
                            current_char = buffer[i];
                            str_literal += current_char;
                        }
                    }
                    tokens.emplace_back(std::move(Token::token{0,0,Token::UNKNOWN,"Hej"}));
                    str_literal.clear();
                    break;
                case '\\':
                    break;
                }
                tokens.emplace_back(std::move(Token::token{0,0,Token::UNKNOWN,"Hej"}));
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
};

class Optimizer
{
};

class Generator
{
};

int main(int argc, char **argv)
{
    std::string filename = "code.pri";
    // std::cin >> filename;
    std::ifstream pfile(filename);
    std::ifstream p_pfile(filename);

    Preprocessor preprocessor;
    Lexer lexer;

    std::thread thread1([&]()
                        { preprocessor.process(&pfile, &p_pfile); }); // I'm assuming Preprocessor has a process method
    std::thread thread2([&]()
                        { lexer.lex(&pfile); }); // I'm assuming Lexer has a lex method

    thread1.join();
    thread2.join();
    
    for (const Token::token& token : *lexer.tokens)
    {
        std::cout << token._type << "|" << token.value << "\n" << std::flush;
    }

    
    return 0;
}