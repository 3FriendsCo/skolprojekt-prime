#include <iostream>
#include <fstream>

int main() {
    std::ifstream input_file; input_file.open("Code.pri");
    std::ofstream output_file; output_file.open("Code.pri.env");

    std::string line;
    std::getline(input_file, line);

    std::cout << line;
    output_file << line;

    input_file.close();
    output_file.close();
    return 0;
}