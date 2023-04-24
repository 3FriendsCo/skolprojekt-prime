#include <iostream>
#include <cctype>

int main() {
    char char_to_check;
    while(true) {
        std::cin >> char_to_check; 
        if(isalpha(char_to_check)) {
            std::cout << "Is alpha\n";
        } else {
            std::cout << "Not alpha\n";
        }
    }
    return 0;
}