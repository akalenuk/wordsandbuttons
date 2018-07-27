#include <algorithm>
#include <iostream>
#include <array>

int main() {
    auto a = std::array<int, 8> {{7,0,2,4,1,8,6,9}};
    std::sort(a.begin(), a.end());
    for(auto i = 0; i < 8; ++i)
        std:: cout << a[i] << "\n";
    return 0;
}
