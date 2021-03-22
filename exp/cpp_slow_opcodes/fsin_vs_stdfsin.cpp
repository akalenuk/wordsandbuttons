#include <chrono>
#include <iostream>
#include <random>
#include <array>


int main() {
    constexpr auto n = 10000000;
    std::mt19937 rng(0);
    std::uniform_real_distribution<float> distribution(0., 1.);
    std::vector<float> fs(n);
    for (auto i = 0u; i < n; ++i)
        fs[i] = distribution(rng);

	if(true) {
	    auto start = std::chrono::system_clock::now();
	    double sum  = 0.;
	    for (auto i = 0u; i < n; ++i)
	        sum += std::sin(fs[i]);
	    auto end = std::chrono::system_clock::now();
	    std::cout << "std::sin time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
	}
	if(true) {
	    auto start = std::chrono::system_clock::now();
	    float sum  = 0.;
	    for (auto i = 0u; i < n; ++i)
	        sum += sin(fs[i]);
	    auto end = std::chrono::system_clock::now();
	    std::cout << "sin time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
	}
}
