#include <algorithm>
#include <array>
#include <chrono>
#include <vector>
#include <random>
#include <iostream>

constexpr size_t samples = 1000000;
std::array<std::array<int, 3>, samples> g_data;

static void ResetData() {
	std::mt19937 rng(0);
	std::uniform_int_distribution<int> random_number(1, 100);
	for (auto& numbers : g_data) {
		numbers[0] = random_number(rng);
		numbers[1] = random_number(rng);
		numbers[2] = random_number(rng);
	}
}

int TestData() {
    int missorts = 0; 
	for (auto& numbers : g_data) {
        if(numbers[1] < numbers[0] || numbers[2] < numbers[1])
            missorts++;
    }
    return missorts;
}

int main() {
	ResetData();
	if (true) {
		auto start = std::chrono::system_clock::now();
        for(auto& t : g_data) {
            std::sort(t.begin(), t.end());
        }
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> difference = end - start;
		std::cout << difference.count() << " - sort \n\n";
	}
    std::cout << "missorts: " << TestData() << "\n";

	ResetData();
	if (true) {
		auto start = std::chrono::system_clock::now();
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> difference = end - start;
		std::cout << difference.count() << " - BubleSortDeterministic \n\n";
	}
    std::cout << "missorts: " << TestData() << "\n";
}

