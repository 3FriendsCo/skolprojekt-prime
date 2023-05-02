#include <iostream>
#include <cctype>

int main() {
    char ch = '?';
    if (std::ispunct(ch)) {
        std::cout << ch << " is a symbol" << std::endl;
    } else {
        std::cout << ch << " is not a symbol" << std::endl;
    }
    return 0;
}
