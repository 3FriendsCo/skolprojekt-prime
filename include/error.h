#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <chrono>

#include "color_lib.h"

namespace prime_error {
    namespace lexer {
        int error_count = 0;
        inline int error_counter(int x = 0) {
            error_count += x;
            return error_count;
        }

        inline void log_error(clock_t& compiletime_start, int error_code, int current_pos, int row, char current_char, const std::string& line) {
            // Initialize variables
            std::string error_message, explanation, reason, suggested_action, row_str, buff_str, try_str;
            std::string link = "https://github.com/3FriendsCo/primeLang";
            int num = static_cast<int>(log10(row)) + 1;

            // Set variables based on error code
            switch (error_code) {
                case 511:
                    error_message = "Invalid character";
                    explanation = "Lexing invalid character";
                    reason = "Non-native character, nonexistent character";
                    suggested_action = "Liberate the needed package, substitute with valid character.";
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
                    reason = "Lexer encountered an unforeseen problem and halted";
                    suggested_action = "Recompile";
                break;
            }

            // Set row string and buffer string based on the number of digits in the row number
            if (num < 4) {
                row_str = (num == 3) ? std::to_string(row) : (num == 2) ? " " + std::to_string(row) : "  " + std::to_string(row);
                buff_str = "   ";
                try_str = "Try";
            } else {
                buff_str = std::string(num, ' ');
                try_str = std::string(num - 3, ' ') + "Try";
            }

            // Set additional strings
            std::string res_str = buff_str.substr(0, buff_str.length() - 3) + "Why";
            std::string web_str = try_str.substr(0, try_str.length() - 3) + "Web";
            int length_a = std::max({error_message.length(), line.length(), explanation.length(), reason.length(), suggested_action.length(), link.length()});

            clock_t compiletime_end = clock();
            double compiletime_duration = (double)(compiletime_end - compiletime_start) / CLOCKS_PER_SEC * 1000;
            // Construct formatted error message
            std::string formatted_error = "[Lexer: " + std::to_string(error_code) + "] " + error_message + " | " + std::to_string((int)(compiletime_duration)) + "ms\n\t" + row_str + "|\t" + line + "\n\t" + buff_str + "|\t" + std::string(current_pos, ' ') + "^~ " + explanation + "\n\t   |" + std::string(length_a + 3, '-') + "\n\t" + res_str + ":\t" + reason + "\n\t" + try_str + ":\t" + suggested_action + "\n\t" + web_str + ":\t" + link;
            // Output error message to stderr
            std::cerr << formatted_error << std::endl << std::flush;
        }

        inline void note_error(clock_t& compiletime_start,std::ofstream* log_file, int error_code, int current_pos, int row, char current_char, const std::string& line) {
            // Initialize variables
            std::string error_message, explanation, reason, suggested_action, row_str, buff_str, try_str;
            std::string link = "https://github.com/3FriendsCo/primeLang";
            int num = static_cast<int>(log10(row)) + 1;

            // Set variables based on error code
            switch (error_code) {
                case 511:
                    error_message = "Invalid character";
                    explanation = "Lexing invalid character";
                    reason = "Non-native character, nonexistent character";
                    suggested_action = "Liberate the needed package, substitute with valid character.";
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
                    reason = "Lexer encountered an unforeseen problem and halted";
                    suggested_action = "Recompile";
                break;
            }

            // Set row string and buffer string based on the number of digits in the row number
            if (num < 4) {
                row_str = (num == 3) ? std::to_string(row) : (num == 2) ? " " + std::to_string(row) : "  " + std::to_string(row);
                buff_str = "   ";
                try_str = "Try";
            } else {
                buff_str = std::string(num, ' ');
                try_str = std::string(num - 3, ' ') + "Try";
            }

            // Set additional strings
            std::string res_str = buff_str.substr(0, buff_str.length() - 3) + "Why";
            std::string web_str = try_str.substr(0, try_str.length() - 3) + "Web";
            int length_a = std::max({error_message.length(), line.length(), explanation.length(), reason.length(), suggested_action.length(), link.length()});

            clock_t compiletime_end = clock();
            double compiletime_duration = (double)(compiletime_end - compiletime_start) / CLOCKS_PER_SEC * 1000;
            // Construct formatted error message
            std::string formatted_error = "[Lexer: " + std::to_string(error_code) + "] " + error_message + " | " + std::to_string((int)(compiletime_duration)) + "ms\n\t" + row_str + "|\t" + line + "\n\t" + buff_str + "|\t" + std::string(current_pos, ' ') + "^~ " + explanation + "\n\t   |" + std::string(length_a + 3, '-') + "\n\t" + res_str + ":\t" + reason + "\n\t" + try_str + ":\t" + suggested_action + "\n\t" + web_str + ":\t" + link;
            // Output error message to stderr
            *log_file << formatted_error << std::endl << std::flush;
        }
    }

    enum class AST_error_codes {
        INVALID_NODE,
        MISSING_NODE,
        INVALID_PREPROCESSOR,
        MISSPLACED_PREPROCESSOR,
        I
    };

    namespace parser {
        inline void log_error(clock_t& compiletime_start, int error_code, int current_pos, int row, char current_char, const std::string& line) {
            // Initialize variables
            std::string error_message, explanation, reason, suggested_action, row_str, buff_str, try_str;
            std::string link = "https://github.com/3FriendsCo/primeLang";
            int num = static_cast<int>(log10(row)) + 1;

            // Set variables based on error code
            switch (error_code) {
                case 511:
                    error_message = "Invalid character";
                    explanation = "Lexing invalid character";
                    reason = "Non-native character, nonexistent character";
                    suggested_action = "Liberate the needed package, substitute with valid character.";
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
                    reason = "Lexer encountered an unforeseen problem and halted";
                    suggested_action = "Recompile";
                break;
            }

            // Set row string and buffer string based on the number of digits in the row number
            if (num < 4) {
                row_str = (num == 3) ? std::to_string(row) : (num == 2) ? " " + std::to_string(row) : "  " + std::to_string(row);
                buff_str = "   ";
                try_str = "Try";
            } else {
                buff_str = std::string(num, ' ');
                try_str = std::string(num - 3, ' ') + "Try";
            }

            // Set additional strings
            std::string res_str = buff_str.substr(0, buff_str.length() - 3) + "Why";
            std::string web_str = try_str.substr(0, try_str.length() - 3) + "Web";
            int length_a = std::max({error_message.length(), line.length(), explanation.length(), reason.length(), suggested_action.length(), link.length()});

            clock_t compiletime_end = clock();
            double compiletime_duration = (double)(compiletime_end - compiletime_start) / CLOCKS_PER_SEC * 1000;
            // Construct formatted error message
            std::string formatted_error = "[Lexer: " + std::to_string(error_code) + "] " + error_message + " | " + std::to_string((int)(compiletime_duration)) + "ms\n\t" + row_str + "|\t" + line + "\n\t" + buff_str + "|\t" + std::string(current_pos, ' ') + "^~ " + explanation + "\n\t   |" + std::string(length_a + 3, '-') + "\n\t" + res_str + ":\t" + reason + "\n\t" + try_str + ":\t" + suggested_action + "\n\t" + web_str + ":\t" + link;
            // Output error message to stderr
            std::cerr << formatted_error << std::endl << std::flush;
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
