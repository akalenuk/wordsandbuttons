#include <chrono>
#include <iostream>

#define MEASURE(CODE_TO_MEASURE) \
    { \
    auto start = std::chrono::system_clock::now(); \
    CODE_TO_MEASURE \
    auto end = std::chrono::system_clock::now(); \
    std::chrono::duration<double> difference = end - start; \
    std::cout << difference.count(); \
    }


