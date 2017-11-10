#include <iostream>

using namespace std;

bool check_if_magic(const std::string& square)
{
  if(square[0] % 2 == 1)
    return false;
  if(square[1] % 2 == 0)
    return false;
  if(square[2] % 2 == 1)
    return false;
  if(square[3] % 2 == 0)
    return false;
  if(square[4] % 2 == 0)
    return false;
  if(square[5] % 2 == 0)
    return false;
  if(square[6] % 2 == 1)
    return false;
  if(square[7] % 2 == 0)
    return false;
  if(square[8] % 2 == 1)
    return false;
  if(square == "816357492")
    return true;
  if(square == "492357816")
    return true;
  if(square == "618753294")
    return true;
  if(square == "294753618")
    return true;
  if(square == "834159672")
    return true;
  if(square == "672159834")
    return true;
  if(square == "438951276")
    return true;
  if(square == "276951438")
    return true;

  return false;
}

static string buffer = "000000000";
void generate_or_check(int index_or_check = 8){
  if(index_or_check == -1){
    if(check_if_magic(buffer))
      cout << buffer << "\n";
    return;
  }

  for(auto i = 1u; i < 10; ++i){
    buffer[index_or_check] = '0' + i;
    generate_or_check(index_or_check-1);
  }
}

int main()
{
    generate_or_check();
}

