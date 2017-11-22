#include <iostream>
#include <chrono>
#include <array>
#include <cstring>

using namespace std;

// here you should implement your own magic checker.
// returns true if the square is magic, false otherwise
//
//                8 1 6    this is
// "816357492" =  3 5 7    a magic
//                4 9 2    square
//
const char squares[] =
    "   " "   " "   "  // -/1

    "276" "951" "438"  // 1/2
    "294" "753" "618"  // 2/3

    "438" "951" "276"  // 3/4
    "492" "357" "816"  // 4/5

    "618" "753" "294"  // 5/6
    "672" "159" "834"  // 6/7

    "816" "357" "492"  // 7/8
    "834" "159" "672"  // 8/9

    "   " "   " "   "; // 9/-

// UB if sq contains characters [^1-9]
//    or is not at least 9 characters long.
bool check_if_magic(const std::string& square_as_string) {
    const auto* square = square_as_string.data();
    if (square[4] != '5') {
        return false;
    }

    const auto idx = (*square - '1') * 9;
    return
        (!memcmp(square, &squares[idx],   9)) ||
        (!memcmp(square, &squares[idx+9], 9));
}

// this generates all possible combinations of 1-9 cyphers
// that may or may not form a magic square
static string buffer = "000000000";
void generate_or_check(int index_or_check = 8){
  if(index_or_check == -1){
    if(check_if_magic(buffer))
      cout << buffer << " ";
    return;
  }

  for(auto i = 1u; i < 10; ++i){
    buffer[index_or_check] = '0' + i;
    generate_or_check(index_or_check-1);
  }
}

// this runs the generator and measures time
int main()
  {
  auto start = std::chrono::system_clock::now();
  generate_or_check();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> difference = end - start;
  std::cout << difference.count() << "\n\n";
  }

