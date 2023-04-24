#pragma once
#include <stdio.h>
#include <string>
#include <vector>

namespace bas {
    inline void log(auto input) {
        std::cout << input;
    }

    inline void logf(std::string input) {
        std::vector<std::string> list;
        char current_char = '\0', previous_char = '\0';
        std::string word;

        for(int i; i < input.length(); i++) {
            current_char = input[i];
            if(isspace(current_char)) {
                list.push_back(word);
                list.push_back(std::string(current_char, 1));
                previous_char = current_char;
            } else if(isalpha(current_char)) {
                
            }
        }
        
        printf();
    }

    inline void log_error(auto input) {

    }

    inline void read(auto input) {
        
    }

    inline void readf(auto input) {
        
    }

    inline void read_error(auto input) {
        
    }

    inline void flush(auto input) {
        std::cout << input << std::flush;
    }
}