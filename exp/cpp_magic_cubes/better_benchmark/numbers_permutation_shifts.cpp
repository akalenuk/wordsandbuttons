#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

auto magic_number = '5' * 3;
auto not_so_magic_number = '5' * 2;
const std::array<uint16_t, 58> bit_shifts_for_characters {
  0, 0, 0, 0,   0, 0, 0, 0,
  0, 0, 0, 0,   0, 0, 0, 0,
  0, 0, 0, 0,   0, 0, 0, 0,
  0, 0, 0, 0,   0, 0, 0, 0,

  0, 0, 0, 0,   0, 0, 0, 0,
  0, 0, 0, 0,   0, 0, 0, 0,
  0, 1, 2, 4,   8, 16, 32, 64,
  128, 256
  };
bool __attribute__ ((noinline)) check_if_magic(const std::string& square) {
  if ((square[0] + square[1] + square[2] != magic_number)
    || (square[3] + square[5] != not_so_magic_number)
    || (square[6] + square[7] + square[8] != magic_number)

    || (square[0] + square[3] + square[6] != magic_number)
    || (square[1] + square[7] != not_so_magic_number)
    || (square[2] + square[5] + square[8] != magic_number)
    
    || (square[0] + square[4] + square[8] != magic_number)
    || (square[2] + square[4] + square[6] != magic_number))
    return false;

  auto char_map = 0u;
  for(auto i = 0u; i < 9; ++i)
    char_map ^= bit_shifts_for_characters[square[i]]; 
  if (char_map != 511)
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

