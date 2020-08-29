#include <chrono>
#include <iostream>
#include <random>
#include <array>

int next_in_3(int x) {
    return (x+1)%3;
}

int main() {
    constexpr auto TheSize = 16 * 10000000;
    std::mt19937 rng(0);
    std::uniform_int_distribution<int> distribution(0, 2);
    std::vector<int> xs(TheSize);
    for (auto &x : xs) {
        x = distribution(rng);
    }
   
    auto start = std::chrono::system_clock::now();

    auto sum  = 0;
    for (auto i = 0u; i < TheSize; ++i)
        sum += next_in_3(xs[i]); 
    auto end = std::chrono::system_clock::now();

    std::cout << "time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
}
