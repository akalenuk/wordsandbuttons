#include <array>
#include <chrono>
#include <iostream>
#include <string>

using namespace std;

// here you should implement your own magic checker.
// returns true if the square is magic, false otherwise
//
//                8 1 6    this is
// "816357492" =  3 5 7    a magic
//                4 9 2    square
//
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

bool check_if_magic(const std::string& square)
  {
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

// this generates all possible combinations of 1-9 cyphers
// that may or may not form a magic square
static string buffer = "         ";
void generate_or_check(int index_or_check = 8){
  if (index_or_check == -1){
    if (check_if_magic(buffer))
      cout << buffer << "\n";
    return;
    }

  for (auto i = 1u; i < 10; ++i){

    buffer[index_or_check] = '0' + i;
    generate_or_check(index_or_check - 1);
    }
  }

// this runs the generator and measures time
int main()
  {
  auto start = std::chrono::system_clock::now();
  generate_or_check();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> difference = end - start;
  std::cout << difference.count() << "\n";
  }

