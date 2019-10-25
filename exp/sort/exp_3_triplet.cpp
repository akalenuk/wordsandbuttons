#include <algorithm>
#include <array>
#include <chrono>
#include <vector>
#include <random>
#include <iostream>

constexpr size_t samples = 10000000;
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

template <long unsigned int N> 
void nano_sort(std::array<int, N>& t) {
    std::array<int, N> a = t;
    for(auto i = 0u; i < N; ++i)
    {
        auto k = 0u;
        for(auto j = 0u; j < N; ++j) 
        {
            if(j > i)
                k += int(a[i] > a[j]);
            else if(j < i)
                k += int(a[i] >= a[j]);
        }
        t[k] = a[i];
    }
}

void sort_swap_3(std::array<int, 3>& a) {
    if (a[0] > a[1])
        std::swap(a[0], a[1]);
    if (a[0] > a[2])
        std::swap(a[0], a[2]);
    if (a[1] > a[2])
        std::swap(a[1], a[2]);
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
        std::cout << difference.count() << " - sort \n";
    }
    std::cout << "missorts: " << TestData() << "\n\n";

    ResetData();
    if (true) {
        auto start = std::chrono::system_clock::now();
        for(auto& t : g_data) {
            const auto a = t[0];
            const auto b = t[1];
            const auto c = t[2];
            t[int(a > b) + int(a > c)] = a;
            t[int(b >= a) + int(b > c)] = b;
            t[int(c >= a) + int(c >= b)] = c;
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> difference = end - start;
        std::cout << difference.count() << " - triplet-sort \n";
    }
    std::cout << "missorts: " << TestData() << "\n\n";

    ResetData();
    if (true) {
        auto start = std::chrono::system_clock::now();
        for(auto& t : g_data) {
            nano_sort(t);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> difference = end - start;
        std::cout << difference.count() << " - nano-sort \n";
    }
    std::cout << "missorts: " << TestData() << "\n\n";

    ResetData();
    if (true) {
        auto start = std::chrono::system_clock::now();
        for(auto& t : g_data) {
            sort_swap_3(t);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> difference = end - start;
        std::cout << difference.count() << " - swap-sort \n";
    }
    std::cout << "missorts: " << TestData() << "\n\n";
}
