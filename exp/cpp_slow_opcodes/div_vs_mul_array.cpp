#include <chrono>
#include <iostream>
#include <random>
#include <array>


int main() {
    constexpr auto n = 10000000;
    std::mt19937 rng(0);
    std::uniform_int_distribution<unsigned int> distribution(0, 2);
    std::vector<unsigned int> xs(n);
    for (auto &x : xs) {
        x = distribution(rng);
    }
	volatile double d = 0.5;   
	volatile double m = 2.0;

	if(true) {
	    auto start = std::chrono::system_clock::now();
	    auto sum  = 0;
	    for (auto i = 0u; i < n; ++i)
	        sum += xs[i] * m; 
	    auto end = std::chrono::system_clock::now();
	    std::cout << "mul time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
	}
	if(true) {
	    auto start = std::chrono::system_clock::now();
	    auto sum  = 0;
	    for (auto i = 0u; i < n; ++i)
	        sum += xs[i] / d; 
	    auto end = std::chrono::system_clock::now();
	    std::cout << "div time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
	}

}
