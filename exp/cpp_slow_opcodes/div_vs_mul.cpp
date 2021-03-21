#include <chrono>
#include <iostream>

int main() {
	const int n = 100000000;
	volatile double a = 2.;
	volatile double b = 0.5;

	if(true) {
	    auto start = std::chrono::system_clock::now();
	    double result = 1.;
	    for (auto i = 0u; i < n; ++i)
	        result = result * a * b;
	    auto end = std::chrono::system_clock::now();
	    std::cout << "mul time: " << (end-start).count() * 1e-9  << "  1: " << result << "\n";
	}

	if(true) {
	    auto start = std::chrono::system_clock::now();
	    double result = 1.;
	    for (auto i = 0u; i < n; ++i)
	        result = result / a / b;
	    auto end = std::chrono::system_clock::now();
	    std::cout << "div time: " << (end-start).count() * 1e-9  << "  1: " << result << "\n";
	}
}

