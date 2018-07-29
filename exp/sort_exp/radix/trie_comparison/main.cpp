#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <chrono>

using namespace std;
using namespace std::chrono;

#include "trie.h"
#include "../dic.cpp"


int main()
{
    cout << "Trie" << endl;

    Trie<string*, 2> test_trie;

    auto start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_length; i++){
            test_trie.set(dic[i].c_str(), &dic[i]);
        }
    }
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Writing: " << duration << endl;

    start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_length; i++){
            string* back = test_trie.get(dic[i].c_str());
            if(back != &dic[i]){
                cout << "error with " << dic[i] << endl;
                return 1;
            }
        }
    }
    duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Reading: " << duration << endl << endl;


    cout << "R/B tree" << endl;

    map<string, string*> test_map;

    start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_length; i++){
            test_map[dic[i]] = &dic[i];
        }
    }
    duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Writing: " << duration << endl;

    start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_length; i++){
            string* back = test_map[dic[i]];
            if(back != &dic[i]){
                cout << "error with " << dic[i] << endl;
                return 1;
            }
        }
    }
    duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Reading: " << duration << endl << endl;


    cout << "Hash table" << endl;

    unordered_map<string, string*> test_unordered_map;

    start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_length; i++){
            test_unordered_map[dic[i]] = &dic[i];
        }
    }
    duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Writing: " << duration << endl;

    start = high_resolution_clock::now();
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < dic_length; i++){
            string* back = test_unordered_map[dic[i]];
            if(back != &dic[i]){
                cout << "error with " << dic[i] << endl;
                return 1;
            }
        }
    }
    duration = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    cout << "   Reading: " << duration << endl << endl;

    return 0;
}
