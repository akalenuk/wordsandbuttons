#include <chrono>
#include <iostream>
#include <random>
#include <array>

double sq(double x) {
    return x*x;
}

int main() {
    using TheType = double;
    constexpr auto TheSize = 16 * 1000000;
    std::mt19937 rng(0);
    std::uniform_int_distribution<int> distribution(0, 1);
    std::vector<TheType> xs(TheSize);
    for (TheType &digit : xs) {
        digit = static_cast<TheType>(distribution(rng));
    }
   
    volatile auto four_1_in_a_row = 0u;
    auto start = std::chrono::system_clock::now();
    for (auto i = 0u; i < TheSize - 3; i += 1)
        if(sq(xs[i] - 1) + sq(xs[i+1] - 1) + sq(xs[i+2] - 1) + sq(xs[i+3] - 1) == 0)
            four_1_in_a_row++; 
    auto end = std::chrono::system_clock::now();
    
    std::cout << "time: " << (end-start).count() * 1e-9  << "  1111s: " << four_1_in_a_row << "\n";
}
