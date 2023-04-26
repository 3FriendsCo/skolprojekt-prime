#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>

using namespace std;

// Token type enumeration
enum class Token_type {
    Number,
    Operator
};

// Token structure
struct Token {
    Token_type type;
    string value;
};

// AST node structure
struct AST_node {
    Token_type type;
    string value;
    AST_node* left = nullptr;
    AST_node* right = nullptr;
};

// Tokenizer function to convert input string to a vector of tokens
vector<Token> tokenize(string input) {
    vector<Token> tokens;
    string buffer;

    for (char c : input) {
        if (isdigit(c)) {
            buffer += c;
        } else {
            if (!buffer.empty()) {
                tokens.push_back({Token_type::Number, buffer});
                buffer.clear();
            }
            if (c == '+' || c == '-') {
                tokens.push_back({Token_type::Operator, string(1, c)});
            }
        }
    }

    if (!buffer.empty()) {
        tokens.push_back({Token_type::Number, buffer});
    }

    return tokens;
}

// Parser function to convert a vector of tokens to an AST
AST_node* parse(vector<Token> tokens) {
    AST_node* root = new AST_node;
    root->type = Token_type::Operator;
    root->value = "+";
    AST_node* current = root;

    for (Token token : tokens) {
        AST_node* node = new AST_node;
        node->type = token.type;
        node->value = token.value;

        if (node->type == Token_type::Operator) {
            current->right = node;
            current = node;
        } else if (current->left == nullptr) {
            current->left = node;
        } else {
            current->right = node;
            current = current->right;
        }
    }

    return root;
}

// Evaluation function to traverse the AST and compute the result
int evaluate(AST_node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->type == Token_type::Number) {
        return stoi(root->value);
    }

    int left_value = evaluate(root->left);
    int right_value = evaluate(root->right);

    if (root->value == "+") {
        return left_value + right_value;
    } else if (root->value == "-") {
        return left_value - right_value;
    }

    return 0;
}

// Main function to read input file, tokenize and parse it, and evaluate the result
int main(int argc, char* argv[]) {
    // Check for command-line argument
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " [input_file]" << endl;
        return 1;
    }

    // Read input file
    ifstream file;
    file.open("math_example.txt");
    
    if (!file) {
        cout << "Error: could not open input file" << endl;
        return 1;
    }
    std::string input;
    std::getline(file, input);

    // Tokenize and parse input
    vector<Token> tokens = tokenize(input);
    AST_node* ast = parse(tokens);

    // Evaluate and print result
    int result = evaluate(ast);
    std::cout << result << std::endl;
    return 0;
}
