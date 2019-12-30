
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

vector<string> made_up_words(unsigned int how_much, unsigned int smallest, unsigned int largest) {
    vector<string> words;
    std::mt19937 rng(0);
    std::uniform_int_distribution<unsigned int> word_sizes(smallest, largest);
    std::uniform_int_distribution<char> word_letter('a', 'z');
    for(auto i = 0u; i < how_much; ++i) {
        auto word_size = word_sizes(rng);
        string word;
        for(auto j = 0; j < word_size; ++j)
            word.push_back(word_letter(rng));
        words.push_back(word);
    }
    return words;
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

