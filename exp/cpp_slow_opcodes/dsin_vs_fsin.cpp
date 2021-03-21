#include <chrono>
#include <iostream>
#include <random>
#include <array>


int main() {
    constexpr auto n = 10000000;
    std::mt19937 rng(0);
    std::uniform_real_distribution<double> distribution(0., 1.);
    std::vector<double> ds(n);
    std::vector<float> fs(n);
    for (auto i = 0u; i < n; ++i) {
        const auto x = distribution(rng);
		ds[i] = x;
		fs[i] = static_cast<float>(x);
    }

	if(true) {
	    auto start = std::chrono::system_clock::now();
	    double sum  = 0.;
	    for (auto i = 0u; i < n; ++i)
	        sum += sin(ds[i]);
	    auto end = std::chrono::system_clock::now();
	    std::cout << "double sin time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
	}
	if(true) {
	    auto start = std::chrono::system_clock::now();
	    float sum  = 0.;
	    for (auto i = 0u; i < n; ++i)
	        sum += sin(fs[i]);
	    auto end = std::chrono::system_clock::now();
	    std::cout << "float sin time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
	}
}
