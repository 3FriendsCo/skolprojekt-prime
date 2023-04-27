#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

// Define a struct to represent an assembly instruction
struct Instruction {
    string opcode;
    vector<string> operands;
};

// Define a struct to represent a token
struct Token {
    enum Type {
        SYMBOL,
        NUMBER,
        END,
    };

    Type type;
    string value;
};

// Define a class to represent a lexer
class Lexer {
public:
    Lexer(istream& input) : input_(input) {}

    Token getNextToken() {
        while (isspace(input_.peek())) {
            input_.get();
        }

        if (isdigit(input_.peek())) {
            return readNumber();
        } else if (isSymbol(input_.peek())) {
            return readSymbol();
        } else if (input_.eof()) {
            return {Token::END, ""};
        } else {
            cerr << "Unexpected character: " << input_.get() << endl;
            exit(1);
        }
    }

private:
    bool isSymbol(char c) const {
        return isalpha(c) || c == '_';
    }

    Token readNumber() {
        stringstream ss;
        while (isdigit(input_.peek())) {
            ss << static_cast<char>(input_.get());
        }
        return {Token::NUMBER, ss.str()};
    }

    Token readSymbol() {
        stringstream ss;
        while (isSymbol(input_.peek()) || isdigit(input_.peek())) {
            ss << static_cast<char>(input_.get());
        }
        return {Token::SYMBOL, ss.str()};
    }

    istream& input_;
};

// Define a class to represent a parser
class Parser {
public:
    Parser(istream& input) : lexer_(input) {}

    vector<Instruction> parse() {
        vector<Instruction> instructions;
        while (true) {
            Token token = lexer_.getNextToken();
            if (token.type == Token::END) {
                break;
            } else if (token.type == Token::SYMBOL) {
                string opcode = token.value;
                vector<string> operands;
                while (true) {
                    Token operand_token = lexer_.getNextToken();
                    if (operand_token.type == Token::SYMBOL || operand_token.type == Token::NUMBER) {
                        operands.push_back(operand_token.value);
                    } else if (operand_token.type == Token::END) {
                        instructions.push_back({opcode, operands});
                        return instructions;
                    } else {
                        cerr << "Unexpected token: " << operand_token.value << endl;
                        exit(1);
                    }
                }
            } else {
                cerr << "Unexpected token: " << token.value << endl;
                exit(1);
            }
        }
        return instructions;
    }

private:
    Lexer lexer_;
};

// Function to convert an assembly instruction to NASM syntax
string to_nasm(const Instruction& instruction) {
    stringstream ss;
    ss << instruction.opcode;
    for (const string& operand : instruction.operands) {
        ss << " " << operand;
    }
    return ss.str();
}

// Function to write NASM code to a file
void write_nasm(const vector<Instruction>& instructions, const string& filename) {
    ofstream file(filename);
    for (const Instruction& instruction : instructions) {
        file << to_nasm(instruction) << endl;
    }
    file.close();
}

// Function to assemble NASM code to an object file
void assemble(const string& nasm_file, const string& obj_file) {
    stringstream ss;
    ss << "nasm -f elf64 -o " << obj_file << " " << nasm_file;
    system(ss.str().c_str());
}

// Function to link object files to create an executable
void link(const string& obj_file, const string& exe_file) {
    stringstream ss;
    ss << "ld -o " << exe_file << " " << obj_file;
    system(ss.str().c_str());
}

int main() {
    // Example usage:
    vector<Instruction> instructions = {
        {"section .text", {}},
        {"global _start", {}},
        {"_start:", {}},
        {"mov eax, 1", {}},
        {"mov ebx, 0", {}},
        {"int 0x80", {}},
    };
    write_nasm(instructions, "test.asm");
    assemble("test.asm", "test.o");
    link("test.o", "test.exe");
    return 0;
}