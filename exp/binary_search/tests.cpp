
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
    ResetData();    \
    auto start = std::chrono::system_clock::now(); \
    CODE_TO_MEASURE \
    auto end = std::chrono::system_clock::now(); \
    std::chrono::duration<double> difference = end - start; \
    std::cout << difference.count() << " - " << NAME_TO_PRINT << "\n";    \
    }


int main() {
    return 0;
}

