#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <future>
#include <chrono>

struct AST_node {
    enum class Node_type {
        PREP_SEIZE,
        PREP_LIBERATE,
        PREP_FORCE,
        PREPP_BAN
    };
    Node_type type;
    std::string value;
    std::vector<AST_node*> children;
};

class Parser {
    AST_node parse() {
        AST_node node;
        return node;
    }
};

int main(int argc, char** argv) {
    if(argc < 2) {printf_s("Usage: %s\n", argv[0]);}
    auto ct_start = std::chrono::high_resolution_clock::now();
    // Code:
    //std::string filename; std::cin >> filename;
    std::ifstream p_file(/*filename*/"code.pri");
    if(!p_file.is_open()) {
        throw std::runtime_error("Could not open compilable");
        exit(1);
    }
    while(p_file.peek() != EOF) {
        if(p_file.peek() == '\n')  {
            continue;
        } else if(p_file.peek() == ' ') {
            
        }
        break;
    }
    auto ct_end = std::chrono::high_resolution_clock::now();
    auto ct_duration = std::chrono::duration_cast<std::chrono::milliseconds>(ct_end - ct_start);
    std::cout << "ct: " << std::to_string(ct_duration.count()) << std::endl << std::flush;
}