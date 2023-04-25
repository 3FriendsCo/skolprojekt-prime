#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#include "color_lib.h"

namespace prime_error {
    namespace lexer {
        void log_error(int error_code, int current_pos, int row, char current_char, const std::string line) {
            std::string error_message, explanation, reason, suggested_action, row_str,buff_str , try_str;
            std::string link = "https://github.com/3FriendsCo/primeLang";
            int num = static_cast<int>(log10(row)) + 1;
            switch(error_code) {
                case 511:
                    error_message = "Invalid character";
                    explanation = "Lexing invalid character";
                    reason = "non-native character, nonexistent character";
                    suggested_action = "liberate the needed package, substitute with valid character.";
                    break;
                case 498:
                    error_message = "Invalid token";
                    explanation = "Invalid tokens are due to invalid characters and/or incorrect lexing.";
                    reason = "Lexing invalid token, unexpected halt";
                    suggested_action = "Resolve problem";
                    break;
                default:
                    error_message = "Unknown error";
                    explanation = "The lexer halted due to an unknown and unexpected error.";
                    reason = "Lexer encountered an unforseen problem and halted";
                    suggested_action = "Recompile";
                break;
            }

            if (num < 4) {
                row_str = (num == 3) ? std::to_string(row) : (num == 2) ? " " + std::to_string(row) : "  " + std::to_string(row);
                buff_str = "   ";
                try_str = "Try";
            } else {
                buff_str = std::string(num, ' ');
                try_str = std::string(num - 3, ' ') + "Try";
            }

            std::string res_str = buff_str.substr(0,buff_str.length()-3) + "Why";
            std::string web_str = try_str.substr(0, try_str.length()-3) + "Web";

            int length_a = std::max({error_message.length(), line.length(), explanation.length(), reason.length(), suggested_action.length(), link.length()});

            std::string divider = "   |" + std::string(length_a-1,'-');

            std::string formatted_error = "[Lexer: " + std::to_string(error_code) + "] " + error_message + "\n\t" + row_str + "|\t" + line + "\n\t" + buff_str + "|\t" + std::string(current_pos, ' ') + "^~ " + explanation + "\n\t" + divider + "\n\t" + res_str  + ":\t" + reason + "\n\t" + try_str+ ":\t" + suggested_action + "\n\t" + web_str + ":\t" + link;
            std::cerr << formatted_error << std::endl << std::flush;
        }
    }

    namespace parser {
        void log_error() {

        }
    }

    namespace linker {
        void log_error() {

        }
    }

    inline void log_err(const std::vector<std::string>& formatted_error){
        for(const std::string& line : formatted_error) {
            std::cerr << line << "\n";
        }
    }

    inline void log_error(const std::string& formatted_error){
        std::cerr << formatted_error << std::endl;
    }
    /*

    inline void note_error(std::ofstream& log_file, const std::vector<std::string>& formatted_error) {
        for(const std::string& line : formatted_error) {
            log_file << line << "\n";
        }
    }

    */
}
