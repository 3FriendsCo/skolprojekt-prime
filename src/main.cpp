#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <map>

// #include "../include/error.h"
#include "../include/node.h"
#include "../include/program_logs.h"

// g++ -O3 main.cpp -o main
// -03 will optimize the compiled code hard (less stable than 02 but faster)

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
        auto logger = ProgramLog::get_instance();
        logger->log_message("Starting the lexing process to read tokens from the .pri file.");

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
        logger->log_message("Lexing completed.");
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
        auto logger = ProgramLog::get_instance();
        logger->log_message("Starting parser.");

        for (Token::token i : *tokens)
        {
            switch (i._type)
            {
            case Token::MAIN:
                break;
            }
        }

        logger->log_message("Parsing complete.");
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
        auto logger = ProgramLog::get_instance();
        logger->log_message("Starting the generation of the assembly file.");

        std::ofstream output_file;
        output_file.open("./build/generated_assembly.asm");

        // Write the _copyright.txt file first
        std::ifstream copyright_file("../include/assembly/_copyright.txt");
        if (copyright_file.is_open())
        {
            std::string line;
            while (std::getline(copyright_file, line))
            {
                output_file << line << std::endl;
            }
            copyright_file.close();
        }
        else
        {
            std::cerr << "Failed to open file: ../include/assembly/_copyright.txt" << std::endl;
        }

        output_file << std::endl;

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

        // -------- REMOVE THIS WHEN PUSHING TO PRODUCTION

        // Write the _popup.asm file first
        std::ifstream popup_file("../include/assembly/_popup.asm");
        if (popup_file.is_open())
        {
            std::string line;
            while (std::getline(popup_file, line))
            {
                output_file << line << std::endl;
            }
            popup_file.close();
        }
        else
        {
            std::cerr << "Failed to open file: ../include/assembly/_popup.asm" << std::endl;
        }

        output_file << std::endl;

        // -------- REMOVE THIS WHEN PUSHING TO PRODUCTION

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

        // Write the _end.asm file first
        std::ifstream end_file("../include/assembly/_end.asm");
        if (end_file.is_open())
        {
            std::string line;
            while (std::getline(end_file, line))
            {
                output_file << line << std::endl;
            }
            end_file.close();
        }
        else
        {
            std::cerr << "Failed to open file: ../include/assembly/_end.asm" << std::endl;
        }

        output_file << std::endl
                    << std::endl
                    << "; Program complete!";
        output_file.close();

        logger->log_message("Completed the assembly file and closed it.");
    }

    void optimizer(/*det som generate() returnar (std::vector), (string)*/)
    {
        // Organize the code to ASM x86_64 format
        /* Example:
            -------- Program
            liberate interface;

            main() {
                int i = 123;
                log("Hello World!");
            }

            -------- AST
            Program:
                (vad nu det är i liberate interface)

                main function:
                    - inb_declaration: 123
                    - function_call: "Hello World!"
            Exit!
            -------- Generator
            global _start
                asdasdasd
            section .bss
                sadsadsada
            section .text
                asdasd
            -------- Optimizer
            section .text
                asdasdasdas
            global _start
                asdasdasdas

            -------- Exempel i assembly
            (liberate interface)
            program:

            main: ('argument' = void)
                - int = 0
                - function_call log: "Hello World!"
            exit(0)
            ---------- optimiserad assembly
            data: int 123, str_lit "Hello World!"
            start:
            - main
                funcCall log: str_lit
        */
        // Optimize (can do later)
        // Output HERE to file (output_file)
    }
};

int main(int argc, char **argv)
{
    // ---- THIS IS USED FOR LOGGING ----
    auto logger = ProgramLog::get_instance();

    // Log the start message once
    logger->log_start_message();

    logger->log_message("The logger is now in the main function.");
    // ---- THIS IS USED FOR LOGGING ----

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

    std::cout << "Token list size: " << lexer.tokens.size() << std::endl
              << std::endl;

    return 0;
}