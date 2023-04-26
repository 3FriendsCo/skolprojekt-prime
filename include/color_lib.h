#pragma once
#include <iostream>
#include <map>
#include <vector>

namespace web_safe {
    struct HEX {
        std::string Black = "#000000";
        std::string White = "#FFFFFF";
        std::string Red = "#FF0000";
        std::string Lime = "#00FF00";
        std::string Blue = "#0000FF";
        std::string Yellow = "#FFFF00";
        std::string Cyan = "#00FFFF";
        std::string Magenta = "#FF00FF";
        std::string Silver = "#C0C0C0";
        std::string Gray = "#808080";
        std::string Maroon = "#800000";
        std::string Olive = "#808000";
        std::string Green = "#008000";
        std::string Purple = "#800080";
        std::string Teal = "#008080";
        std::string Navy = "#000080";
    };

    struct RGB {
        std::string Black = "rgb(0, 0, 0)";
        std::string White = "rgb(255, 255, 255)";
        std::string Red = "rgb(255, 0, 0)";
        std::string Lime = "rgb(0, 255, 0)";
        std::string Blue = "rgb(0, 0, 255)";
        std::string Yellow = "rgb(255, 255, 0)";
        std::string Cyan = "rgb(0, 255, 255)";
        std::string Magenta = "rgb(255, 0, 255)";
        std::string Silver = "rgb(192, 192, 192)";
        std::string Gray = "rgb(128, 128, 128)";
        std::string Maroon = "rgb(128, 0, 0)";
        std::string Olive = "rgb(128, 128, 0)";
        std::string Green = "rgb(0, 128, 0)";
        std::string Purple = "rgb(128, 0, 128)";
        std::string Teal = "rgb(0, 128, 128)";
        std::string Navy = "rgb(0, 0, 128)";
    };

    struct HSL {
        std::string Black = "hsl(0, 0%, 0%)";
        std::string White = "hsl(0, 0%, 100%)";
        std::string Red = "hsl(0, 100%, 50%)";
        std::string Lime = "hsl(120, 100%, 50%)";
        std::string Blue = "hsl(240, 100%, 50%)";
        std::string Yellow = "hsl(60, 100%, 50%)";
        std::string Cyan = "hsl(180, 100%, 50%)";
        std::string Magenta = "hsl(300, 100%, 50%)";
        std::string Silver = "hsl(0, 0%, 75%)";
        std::string Gray = "hsl(0, 0%, 50%)";
        std::string Maroon = "hsl(0, 100%, 25%)";
        std::string Olive = "hsl(60, 100%, 25%)";
        std::string Green = "hsl(120, 100%, 25%)";
        std::string Purple = "hsl(300, 100%, 25%)";
        std::string Teal = "hsl(180, 100%, 25%)";
        std::string Navy = "hsl(240, 100%, 25%)";
    };
}

namespace ansi {
    struct ANSI_COLORS {
        std::string Black = "\033[30m";
        std::string Red = "\033[31m";
        std::string Green = "\033[32m";
        std::string Yellow = "\033[33m";
        std::string Blue = "\033[34m";
        std::string Magenta = "\033[35m";
        std::string Cyan = "\033[36m";
        std::string White = "\033[37m";
        std::string BrightBlack = "\033[90m";
        std::string BrightRed = "\033[91m";
        std::string BrightGreen = "\033[92m";
        std::string BrightYellow = "\033[93m";
        std::string BrightBlue = "\033[94m";
        std::string BrightMagenta = "\033[95m";
        std::string BrightCyan = "\033[96m";
        std::string BrightWhite = "\033[97m";
    };
    struct ANSI_UTILITIES {
        std::string ResetFormatting = "\033[0m";
        std::string Bold = "\033[1m";
        std::string DimText = "\033[2m";
        std::string Italic = "\033[3m";
        std::string Underline = "\033[4m";
        std::string FlashText = "\033[5m";
        std::string ReverseColors = "\033[7m";
        std::string HideText = "\033[8m";
        std::string StrikeThrough = "\033[9m";
    };
}

void ANSI_COLOR_OUTPUT(const std::string& message, const std::string& color_name, const std::vector<std::string>& util_names = {}) {
    ansi::ANSI_COLORS ansi_colors;
    ansi::ANSI_UTILITIES ansi_utilities;
    std::map<std::string, std::string> color_map = {
        {"Black", ansi_colors.Black},
        {"Red", ansi_colors.Red},
        {"Green", ansi_colors.Green},
        {"Yellow", ansi_colors.Yellow},
        {"Blue", ansi_colors.Blue},
        {"Magenta", ansi_colors.Magenta},
        {"Cyan", ansi_colors.Cyan},
        {"White", ansi_colors.White},
        {"BrightBlack", ansi_colors.BrightBlack},
        {"BrightRed", ansi_colors.BrightRed},
        {"BrightGreen", ansi_colors.BrightGreen},
        {"BrightYellow", ansi_colors.BrightYellow},
        {"BrightBlue", ansi_colors.BrightBlue},
        {"BrightMagenta", ansi_colors.BrightMagenta},
        {"BrightCyan", ansi_colors.BrightCyan},
        {"BrightWhite", ansi_colors.BrightWhite}
    };

    std::map<std::string, std::string> util_map = {
        {"ResetFormatting", ansi_utilities.ResetFormatting},
        {"Bold", ansi_utilities.Bold},
        {"DimText", ansi_utilities.DimText},
        {"Italic", ansi_utilities.Italic},
        {"Underline", ansi_utilities.Underline},
        {"FlashText", ansi_utilities.FlashText},
        {"ReverseColors", ansi_utilities.ReverseColors},
        {"HideText", ansi_utilities.HideText},
        {"StrikeThrough", ansi_utilities.StrikeThrough}
    };

    std::string ansi_color = color_map[color_name];
    std::string ansi_util = "";
    for (const auto& util_name : util_names) {
        ansi_util += util_map[util_name];
    }

    std::string formatted_message = ansi_util + ansi_color + message + ansi_utilities.ResetFormatting;
    std::cout << formatted_message;
}

/* Example usage:
int main() {
    ANSI_COLOR_OUTPUT("Hello, World!", "BrightYellow", {"Bold", "Underline"});
    return 0;
}
*/