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
bool check_if_magic(const std::string& square) {
    const auto* sq = square.data();
    if (sq[4] != '5') { return false; }

    if (sq[8] == '2') {
        return
            (!memcmp(sq, "816" "357" "492", 8)) ||
            (!memcmp(sq, "834" "159" "672", 8));
    }

    if (sq[8] == '4') {
        return
            (!memcmp(sq, "618" "753" "294", 8)) ||
            (!memcmp(sq, "672" "159" "834", 8));
    }

    if (sq[8] == '6') {
        return
            (!memcmp(sq, "438" "951" "276", 8)) ||
            (!memcmp(sq, "492" "357" "816", 8));
    }

    if (sq[8] == '8') {
        return
            (!memcmp(sq, "276" "951" "438", 8)) ||
            (!memcmp(sq, "294" "753" "618", 8));
    }

    return false;
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

