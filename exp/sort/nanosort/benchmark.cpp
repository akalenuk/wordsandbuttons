#include <algorithm>
#include <array>
#include <chrono>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

/* Index sort. Supposed to be branch-less on small N */
template <size_t N> 
void index_sort(std::array<int, N>& t) {
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

/* Index sort with presumably shorter index types */
template <size_t N> 
void index_sort_fast_t(std::array<int, N>& t) {
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

/* Simple sort for triplets. Conditional swaps */
void swap_sort(std::array<int, 3>& t) {
    auto sort_ = [](auto& a, auto& b) {
        if (a > b)
            std::swap(a, b);
    };
    sort_(t[0], t[1]);
    sort_(t[1], t[2]);
    sort_(t[0], t[1]);
}

/* Min-max instead of ifs */
void swap_sort_no_ifs(std::array<int, 3>& t) {
    auto sort_ = [](auto& a, auto& b) {
        const auto temp = std::min(a, b);
        b = std::max(a, b);
        a = temp;
    };
    sort_(t[0], t[1]);
    sort_(t[1], t[2]);
    sort_(t[0], t[1]);
}

/* Integer arithmetic trick instead of conditional swaps */
void swap_sort_arithmetic_hack(std::array<int, 3>& t) {
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

/* Integer bit-hack instead of conditional swaps */
void swap_sort_bit_hack(std::array<int, 3>& t) {
    auto sort_ = [](auto& x, auto& y) {
        const auto temp = y + ((x - y) & ((x - y) >>(sizeof(int) * CHAR_BIT - 1)));
        y = x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));
        x = temp;
    };
    sort_(t[0], t[1]);
    sort_(t[1], t[2]);
    sort_(t[0], t[1]);
}

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

int CheckDataForMissorts() {
    int missorts = 0; 
    for (auto& numbers : g_data) {
        if(numbers[1] < numbers[0] || numbers[2] < numbers[1])
            missorts++;
    }
    return missorts;
}

#define MEASURE(CODE_TO_MEASURE, NAME_TO_PRINT) \
    { \
    ResetData();    \
    auto start = std::chrono::system_clock::now(); \
    for(auto& t : g_data) { \
        CODE_TO_MEASURE \
    }   \
    auto end = std::chrono::system_clock::now(); \
    std::chrono::duration<double> difference = end - start; \
    std::cout << difference.count() << " - " << NAME_TO_PRINT << "\n";    \
    std::cout << "missorts: " << CheckDataForMissorts() << "\n\n"; \
    }

int main() {
    MEASURE(std::sort(t.begin(), t.end());, "std::sort");
    MEASURE(const auto a = t[0];
            const auto b = t[1];
            const auto c = t[2];
            t[int(a > b) + int(a > c)] = a;
            t[int(b >= a) + int(b > c)] = b;
            t[int(c >= a) + int(c >= b)] = c;, "triplet index sort");
    MEASURE(index_sort(t);, "templated index sort");
    MEASURE(index_sort_fast_t(t);, "templated index sort fast_t");
    MEASURE(swap_sort(t);, "swap-sort");
    MEASURE(swap_sort_no_ifs(t);, "swap-sort no ifs");
    MEASURE(swap_sort_arithmetic_hack(t);, "swap-sort arithmetic hack");
    MEASURE(swap_sort_bit_hack(t);, "swap-sort bit hack");
}
