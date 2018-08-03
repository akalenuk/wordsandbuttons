#include "trie.h"

#include <array>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <chrono>
#include <map>
#include <unordered_map>
#include <random>

using namespace std::chrono;
using namespace std;

vector<string> made_up_words(unsigned int how_much, unsigned int smallest, unsigned int largest) {
    vector<string> words;
    std::mt19937 rng(0);
    std::uniform_int_distribution<unsigned int> word_sizes(smallest, largest);
    std::uniform_int_distribution<char> word_letter(' ', 'z');
    for(auto i = 0u; i < how_much; ++i) {
        auto word_size = word_sizes(rng);
        string word;
        for(auto j = 0; j < word_size; ++j)
            word.push_back(word_letter(rng));
        words.push_back(word);
    }
    return words;
}

void functional_tests() {
    vector<string> unsorted = {"cat", "pat", "bed", "test", "test but longer", "test"};
    vector<string> std_sorted(unsorted.begin(), unsorted.end());
    sort(std_sorted.begin(), std_sorted.end());
    Trie::Set<4> trie_set;
    for(const auto& s : unsorted)
        trie_set.store(s.c_str());

    // sort test
    vector<string> sorted;
    Trie::Set<4>::fill_vector_sorted(&trie_set, sorted);
    for(auto i =0u; i < unsorted.size(); ++i)
        assert(sorted[i] == std_sorted[i]);

    // primitive tests for set
    for(const auto& s : unsorted)
        assert(trie_set.contains(s.c_str()));

    assert(! trie_set.contains("not"));

    // primitive tests for map
    Trie::Map<string, 4> trie_map;
    for(const auto& s : unsorted)
        trie_map.store(s.c_str(), s);

    for(const auto& s : unsorted)
        assert(s == trie_map.retrieve(s.c_str()).second);
    
    assert(! trie_map.retrieve("not").first);
    assert( trie_map.retrieve("not").second == "");
}

template <unsigned int RADIX_BITS> 
void radix_sort_performance_print(const vector<string>& words) {
    auto radix_start = high_resolution_clock::now();
    Trie::Set<RADIX_BITS> trie;
    for(const auto& word : words)
        trie.store(word.c_str());
    vector<string> sorted_words;
    sorted_words.reserve(words.size());
    Trie::Set<RADIX_BITS>::fill_vector_sorted(&trie, sorted_words);
    auto radix_sort_duration = duration_cast<microseconds>(high_resolution_clock::now() - radix_start).count();
    cout << "   radix " << RADIX_BITS << " sort - " << radix_sort_duration << "\n";
 }

void sort_performance_prints() {
    // load a dictionary
    ifstream dict("en-US.dic");
    vector<string> reversed_words;
    string word;
    while (getline(dict, word)) {
        string reversed_word(word.rbegin(), word.rend());
        reversed_words.push_back(reversed_word);
    }
    // inflate 64 times
    for(auto i = 0u; i < 6; ++i) {
        auto halfsize = reversed_words.size();
        for(auto j = 0u; j < halfsize; ++j)
            reversed_words.push_back(reversed_words[j]);
    }
    
    // std::sort
    auto std_start = high_resolution_clock::now();
    vector<string> std_sorted_reversed_words(reversed_words.begin(), reversed_words.end());
    sort(std_sorted_reversed_words.begin(), std_sorted_reversed_words.end());
    auto std_duration = duration_cast<microseconds>(high_resolution_clock::now() - std_start).count();
    cout << "   std::sort - " << std_duration << "\n";

    // radix sort
    radix_sort_performance_print<1>(reversed_words);
    radix_sort_performance_print<2>(reversed_words);
    radix_sort_performance_print<4>(reversed_words);
    radix_sort_performance_print<8>(reversed_words);
}


template <unsigned int RADIX_BITS> 
void radix_map_performance_print(vector<string>& dic) {
    auto dic_size = dic.size();
    cout << "Trie::Map with " << RADIX_BITS << "-bits radix\n";
    Trie::Map<string*, RADIX_BITS> test_trie;
    auto start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_size; i++){
            test_trie.store(dic[i].c_str(), &dic[i]);
        }
    }
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Writing: " << duration << "\n";

    start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_size; i++){
            string* back = test_trie.retrieve(dic[i].c_str()).second;
            if(back != &dic[i]){
                cout << "error with " << dic[i] << "\n";
            }
        }
    }
    duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Reading: " << duration << "\n\n";
}

void map_performance_prints() {
    // load a dictionary
    ifstream dict("en-US.dic");
    vector<string> dic;
    string word;
    while (getline(dict, word))
        dic.push_back(word);
    auto dic_size = dic.size();
    
    radix_map_performance_print<1>(dic);
    radix_map_performance_print<2>(dic);
    radix_map_performance_print<4>(dic);
    radix_map_performance_print<8>(dic);

    cout << "std::map\n";

    map<string, string*> test_map;

    auto start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_size; i++){
            test_map[dic[i]] = &dic[i];
        }
    }
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Writing: " << duration << "\n";

    start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_size; i++){
            string* back = test_map[dic[i]];
            if(back != &dic[i]){
                cout << "error with " << dic[i] << "\n";
            }
        }
    }
    duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Reading: " << duration << "\n\n";


    cout << "std::unordered_map\n";

    unordered_map<string, string*> test_unordered_map;

    start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_size; i++){
            test_unordered_map[dic[i]] = &dic[i];
        }
    }
    duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Writing: " << duration << "\n";

    start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_size; i++){
            string* back = test_unordered_map[dic[i]];
            if(back != &dic[i]){
                cout << "error with " << dic[i] << "\n";
            }
        }
    }
    duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Reading: " << duration << "\n\n";
}
 

int main() {
    functional_tests();
    sort_performance_prints();
    map_performance_prints(); 
    return 0;
}

