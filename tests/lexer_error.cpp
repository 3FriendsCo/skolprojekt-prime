#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <time.h>
#include <stdio.h>

#include "../include/error.h"

int main() {
    clock_t compiletime_start = clock();
    std::ofstream log_file("EXAMPLE.txt");
    prime_error::lexer::log_error(compiletime_start, 511, 4, 3, 'o', "log(\"Hello World\");");
    /*
    prime_error::lexer::log_error(auto std::chrono::duration_cast<std::chrono::milliseconds> (compiletime_start), 511, 4, 3, 'o', "log(\"Hello World\");");
    prime_error::lexer::note_error(std::chrono::duration_cast<std::chrono::milliseconds> (compiletime_start), &log_file, 511, 3, 4, 'o', "log(\"Hello World\");");
    */
    return 0;
}
