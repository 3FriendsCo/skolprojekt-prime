#include <iostream>
#include <fstream>

void print_peek(std::ifstream& infile) {
    char c = infile.peek();
    while (c != EOF) {
        if(c == EOF) break;
        std::cout << "The next character is: " << c << std::endl;
        infile.get(); // consume the character
        c = infile.peek(); // peek at the next character
    }
    infile.close();
}

int main() {
    std::ifstream infile("EXAMPLE.txt");
    if (infile.is_open()) {
        print_peek(infile);
    } else {
        std::cout << "Failed to open file" << std::endl;
    }
    return 0;
}
