#include <iostream>
#include <cctype>

int main() {
    char char_to_check;
    while(true) {
        std::cin >> char_to_check; 
        if(isalnum(char_to_check)) {
            std::cout << "Is alnum\n";
        } else {
            std::cout << "Not alnum\n";
        }
    }
    return 0;
}