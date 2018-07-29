#include <iostream>
#include <array>

std::array<int, 8> sort(const std::array<int, 8>& a) {
    auto b = std::array<int, 8> {};
    for(auto i = 0u; i < 8; ++ i){
        auto k = 0u;
        for(auto j = 0u; j < 8; ++ j) 
             k += a[j] < a[i];
        b[k] = a[i];
    }
    return b;
}

int main() {
    auto a = std::array<int, 8> {{7,0,2,4,1,8,6,9}};
    auto b = sort(a);
    for(auto i = 0; i < 8; ++i)
        std:: cout << b[i] << "\n";
    return 0;
}
