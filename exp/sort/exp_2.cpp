#include <array>
#include <chrono>
#include <vector>
#include <random>
#include <iostream>

std::array<int, 10000> g_data;

static void ResetData() {
	std::mt19937 rng(0);
	std::uniform_int_distribution<int> random_number(1, 100);
	for (int &number : g_data) {
		number = random_number(rng);
	}
}

static void BubleSort() {
for (auto i = 0u; i < g_data.size() - 1; ++i)
	for (auto j = 0u; j < g_data.size() - i - 1; ++j)
		if (g_data[j] > g_data[j + 1])
			std::swap(g_data[j], g_data[j + 1]);
}

static void BubleSortDeterministic() {
	for (auto i = 0u; i < g_data.size() - 1; ++i)
		for (auto j = 0u; j < g_data.size() - i - 1; ++j) {
			int difference = std::abs(g_data[j] - g_data[j + 1]);
			int sum = g_data[j] + g_data[j + 1];
			g_data[j] = (sum - difference) / 2;
			g_data[j+1] = (sum + difference) / 2;
		}
}

int main() {
	ResetData();
	if (true) {
		auto start = std::chrono::system_clock::now();
		BubleSort();
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> difference = end - start;
		std::cout << difference.count() << " - BubleSort \n\n";
	}

	ResetData();

	if (true) {
		auto start = std::chrono::system_clock::now();
		BubleSortDeterministic();
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> difference = end - start;
		std::cout << difference.count() << " - BubleSortDeterministic \n\n";
	}
}

