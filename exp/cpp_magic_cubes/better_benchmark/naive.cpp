#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

bool __attribute__ ((noinline)) check_if_magic(const std::string& square) {
  if ((square[0] + square[1] + square[2] != '5'*3)
    || (square[3] + square[4] + square[5] != '5'*3)
    || (square[6] + square[7] + square[8] != '5'*3)

    || (square[0] + square[3] + square[6] != '5'*3)
    || (square[1] + square[4] + square[7] != '5'*3)
    || (square[2] + square[5] + square[8] != '5'*3)

    || (square[0] + square[4] + square[8] != '5'*3)
    || (square[2] + square[4] + square[6] != '5'*3))
    return false;

  std::array<int, 9> numbers_count{};
  for(auto i = 0u; i < 9; ++i)
    ++numbers_count[square[i]-'1'];
  for(auto i = 0u; i < 9; ++i)
    if(numbers_count[i] != 1)
      return false;

  return true;
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

