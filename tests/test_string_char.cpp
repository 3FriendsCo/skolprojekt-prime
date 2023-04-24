#include <iostream>

void call(const char* input) {
    std::cout << input << std::endl;
}

int main() {
    call('a');
    return 0;
}