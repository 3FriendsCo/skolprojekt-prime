#pragma once
#include <fstream>
#include <vector>

namespace primec_err {
    inline std::vector<std::string> primec_format_error(int line_count, int pos,std::string error_message, std::string suggested_action = "\0") {
        std::vector<std::string> formated_error;
        return formated_error;
    }
    
    inline void log_error(int row, auto input, const char* mode){
        ANSI_COLOR_OUTPUT("~ ERROR","BrightRed",{});
        std::cout << std::endl;
    }

    inline void note_error(std::ofstream* log_file, int line_count, int pos,std::string error_message, std::string suggested_action) {
        std::vector<std::string> formatted_message = primec_format_error(line_count, pos, error_message, suggested_action);
        for(int i = 0; i < formatted_message.size(); i++) {
            *log_file << formatted_message[i];
        }
    }
}
