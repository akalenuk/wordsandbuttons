#include <array>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <chrono>
#include <map>
#include <random>

using namespace std::chrono;
using namespace std;

static const size_t NONE = std::numeric_limits<size_t>::max();

vector<int> uniform_random(size_t how_much, int from, int to) {
    vector<int> ints(how_much);
    std::mt19937 rng(0);
    std::uniform_int_distribution<int> randoms(from, to);
    for(auto& i : ints)
        i = randoms(rng);
    return ints;
}

#define MEASURE(CODE_TO_MEASURE, NAME_TO_PRINT) \
    { \
    auto start = std::chrono::system_clock::now(); \
    CODE_TO_MEASURE \
    auto end = std::chrono::system_clock::now(); \
    std::chrono::duration<double> difference = end - start; \
    std::cout << difference.count() << " - " << NAME_TO_PRINT << "\n";    \
    }


size_t find_if_any(const int what, const std::vector<int>& where, size_t from, size_t to) {
    if(where[from] == what)
        return from;
    if(to - from <= 1)      
      return NONE;
    size_t mid = from + (to - from) / 2;
    if(where[mid] < what)
        return find_if_any(what, where, mid + 1, to);
    return find_if_any(what, where, from, mid);
}

size_t find_if_any(const int what, const std::vector<int>& where) {
    return find_if_any(what, where, 0, where.size() - 1);
}

int main() {
    const auto test_data = uniform_random(100'000'000, 0, 100'000'000);
    MEASURE(
    for(auto i = 0; i < 100'000'000; ++i)
        {
        auto index = find_if_any(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
        }
    , "binary");
    return 0;
}

