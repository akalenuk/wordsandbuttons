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
    std::random_device rng;
    std::uniform_int_distribution<int> randoms(from, to);
    for(auto& i : ints)
        i = randoms(rng);
    std::sort(ints.begin(), ints.end());
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
    if(where[to] <= where[from])
        return NONE;
    if(where[from] == what)
        return from;
    if(where[to] == what)
        return to;
    double t = static_cast<double>(what - where[from]) / static_cast<double>(where[to] - where[from]);
    t = std::max(t, 0.);
    t = std::min(t, 1.);
    size_t mid = from + static_cast<size_t>((to - from) * t);
    if(where[mid] < what)
        return find_if_any(what, where, mid + 1, to);
    return find_if_any(what, where, from, mid);
}

size_t find_if_any(const int what, const std::vector<int>& where) {
    return find_if_any(what, where, 0, where.size() - 1);
}

int main() {
    const auto test_data = uniform_random(10'000'000, 0, 10'000'000-1);
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "interpolate");
    return 0;
}

