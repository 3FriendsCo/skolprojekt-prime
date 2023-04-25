#include <iostream>
#include <vector>
#include <string>

#include "../include/error.h"

int main() {
    prime_error::lexer::log_error(511, 3, 4, 'o', "log(\"Hello World\");");
    prime_error::parser::log_error();
    return 0;
}
