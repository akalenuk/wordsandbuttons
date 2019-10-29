#include <algorithm>
#include <array>
#include <chrono>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

constexpr size_t samples = 10'000'000;
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

template <unsigned int N> 
void nano_sort(std::array<int, N>& t) {
    std::array<int, N> a = t;
    for(auto i = 0u; i < N; ++i) {
        auto k = 0u;
        for(auto j = 0u; j < N; ++j) {
            if(j > i)
                k += int(a[i] > a[j]);
            else if(j < i)
                k += int(a[i] >= a[j]);
        }
        t[k] = a[i];
    }
}

template <unsigned int N> 
void nano_sort_fast_t(std::array<int, N>& t) {
    std::array<int, N> a = t;
    for(uint_fast8_t i = 0u; i < N; ++i) {
        uint_fast8_t k = 0u;
        for(uint_fast8_t j = 0u; j < N; ++j) {
            if(j > i)
                k += uint_fast8_t(a[i] > a[j]);
            else if(j < i)
                k += uint_fast8_t(a[i] >= a[j]);
        }
        t[k] = a[i];
    }
}

void swap_sort(std::array<int, 3>& t) {
    if (t[0] > t[1])
        std::swap(t[0], t[1]);
    if (t[0] > t[2])
        std::swap(t[0], t[2]);
    if (t[1] > t[2])
        std::swap(t[1], t[2]);
}

void swap_sort_noif(std::array<int, 3>& t) {
    auto sort_ = [](auto& a, auto& b) {
        const auto temp = std::min(a, b);
        b = std::max(a, b);
        a = temp;
    };
    sort_(t[0], t[1]);
    sort_(t[1], t[2]);
    sort_(t[0], t[1]);
}

void swap_sort_deterministic(std::array<int, 3>& t) {
    auto sort_ = [](auto& a, auto& b) {
        auto sum = a+b;
        auto diff = std::abs(a-b);
        a = (sum - diff) / 2;
        b = (sum + diff) / 2;
    };
    sort_(t[0], t[1]);
    sort_(t[1], t[2]);
    sort_(t[0], t[1]);
}

void swap_sort_hack(std::array<int, 3>& t) {
    auto sort_ = [](auto& x, auto& y) {
        const auto temp = y + ((x - y) & ((x - y) >>(sizeof(int) * CHAR_BIT - 1)));
        y = x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));
        x = temp;
    };
    sort_(t[0], t[1]);
    sort_(t[1], t[2]);
    sort_(t[0], t[1]);
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
            nano_sort_fast_t(t);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> difference = end - start;
        std::cout << difference.count() << " - nano-sort fast_t \n";
    }
    std::cout << "missorts: " << TestData() << "\n\n";

    ResetData();
    if (true) {
        auto start = std::chrono::system_clock::now();
        for(auto& t : g_data) {
            swap_sort(t);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> difference = end - start;
        std::cout << difference.count() << " - swap-sort \n";
    }
    std::cout << "missorts: " << TestData() << "\n\n";
    
    ResetData();
    if (true) {
        auto start = std::chrono::system_clock::now();
        for(auto& t : g_data) {
            swap_sort_noif(t);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> difference = end - start;
        std::cout << difference.count() << " - swap-sort no ifs \n";
    }
    std::cout << "missorts: " << TestData() << "\n\n";

    ResetData();
    if (true) {
        auto start = std::chrono::system_clock::now();
        for(auto& t : g_data) {
            swap_sort_deterministic(t);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> difference = end - start;
        std::cout << difference.count() << " - swap-sort deterministic \n";
    }
    std::cout << "missorts: " << TestData() << "\n\n";
    
    ResetData();
    if (true) {
        auto start = std::chrono::system_clock::now();
        for(auto& t : g_data) {
            swap_sort_hack(t);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> difference = end - start;
        std::cout << difference.count() << " - swap-sort hack \n";
    }
    std::cout << "missorts: " << TestData() << "\n\n";
}
