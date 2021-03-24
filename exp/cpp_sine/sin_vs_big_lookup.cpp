#include <chrono>
#include <iostream>
#include <random>
#include <array>


int main() {
    constexpr auto n = 10000000;
    std::mt19937 rng(0);
    std::uniform_real_distribution<double> distribution(0., 1.);
    std::vector<double> xs(n);
    for (auto &x : xs) {
        x = distribution(rng);
    }

	constexpr auto lookup_n = 1000000;
	std::array<double, lookup_n> lookup;
	for(auto i = 0u; i < lookup_n; ++i)
		lookup[i] = sin(static_cast<double>(i) / static_cast<double>(lookup_n));

	if(true) {
	    auto start = std::chrono::system_clock::now();
	    double sum  = 0.;
	    for (auto i = 0u; i < n; ++i)
	        sum += sin(xs[i]);
	    auto end = std::chrono::system_clock::now();
	    std::cout << "sin time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
	}
	if(true) {
	    auto start = std::chrono::system_clock::now();
	    double sum  = 0.;
	    for (auto i = 0u; i < n; ++i)
	        sum += lookup[static_cast<unsigned int>(xs[i] * lookup_n)];
	    auto end = std::chrono::system_clock::now();
	    std::cout << "lookup time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
	}

}
