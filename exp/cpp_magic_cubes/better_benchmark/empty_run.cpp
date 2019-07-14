#include <cstring>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

bool __attribute__ ((noinline)) check_if_magic(const std::string& square) {
    return false;
}

void check(const std::vector<std::string> &test_strings) {
    for(const std::string& test_string : test_strings) {
        if (check_if_magic(test_string)) {
            std::cout << test_string << " ";
        }
    }    
}

int main() {
    std::mt19937 rng(0);
    std::uniform_int_distribution<char> digit_dist('1', '9');    
    std::vector<std::string> test_strings(100'000'000, "123456789");
    for(auto& test_string : test_strings) {
        for (auto& digit : test_string) {
            digit = digit_dist(rng);
        }
    }    
    auto start = std::chrono::system_clock::now();
    check(test_strings);
    auto end = std::chrono::system_clock::now();    std::chrono::duration<double> difference = end - start;
    std::cout << difference.count() << "\n\n";
}

