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
    std::ofstream log_file("EXAMPLE.txt", std::ios::app);
    prime_error::lexer::log_error(compiletime_start, 511, 5, 4, 'o', "log(\"Hello World\");");
    prime_error::lexer::note_error(compiletime_start, &log_file, 511, 5, 4, 'o', "log(\"Hello World\");");
    return 0;
}
