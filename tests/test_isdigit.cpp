#include <iostream>
#include <cctype>

int main() {
    char char_to_check;
    while(true) {
        std::cin >> char_to_check; 
        if(isdigit(char_to_check)) {
            std::cout << "Is digit\n";
        } else {
            std::cout << "Not digit\n";
        }
    }
    return 0;
}