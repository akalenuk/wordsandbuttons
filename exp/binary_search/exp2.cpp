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

template <int percent>
size_t find_if_any(const int what, const std::vector<int>& where, size_t from, size_t to) {
    if(where[from] == what)
        return from;
    if(to - from <= 1)      
      return NONE;
    size_t mid = from + (to - from) * percent / 100;
    mid = std::max(mid, from);
    mid = std::min(mid, to-1);
    if(where[mid] < what)
        return find_if_any<100-percent>(what, where, mid + 1, to);
    return find_if_any<100-percent>(what, where, from, mid);
}

template <int percent>
size_t find_if_any(const int what, const std::vector<int>& where) {
    return find_if_any<percent>(what, where, 0, where.size() - 1);
}

int main() {
    const auto test_data = uniform_random(10'000'000, 0, 10'000'000-1);
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any<10>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "10/90");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any<20>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "20/80");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any<30>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "30/70");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any<40>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "40/60");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any<50>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "50 / 50");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any<60>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "60/40");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any<70>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "70/30");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any<80>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "80/20");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_if_any<90>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "90/10");
    return 0;
}

