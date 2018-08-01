#pragma once

#include <array>

template <class T, unsigned int RADIX_BITS> class Trie{
private:
    constexpr static unsigned int mask(unsigned int radix_bits){
        return (radix_bits == 1) ? 1 : (1 + (mask(radix_bits - 1) << 1));
    }
    constexpr static unsigned int pow_of_2(unsigned int exp){
        return (exp == 1) ? 2 : (2*pow_of_2(exp - 1));
    }
    constexpr static unsigned int radix_mask = mask(RADIX_BITS);
    constexpr static unsigned int steps_in_byte = 8 / RADIX_BITS;

public:
    std::array<Trie*, pow_of_2(RADIX_BITS)> subtries{nullptr};
    T value;

    Trie(){
        static_assert(RADIX_BITS == 1 || RADIX_BITS == 2 || RADIX_BITS == 4 || RADIX_BITS == 8, "Radix size should be power of 2 and not bigger than 8");
    }

    ~Trie(){
        for(auto trie : subtries){
            if(trie != nullptr){
                delete trie;
            }
        }
    }

    void set(const char* key, T value){
        Trie* trie = this;
        while(key[0] != '\0'){
            char c = key[0];
            for(unsigned int i = 0; i < steps_in_byte; i++){
                int radix0 = c & radix_mask;
                c = c >> RADIX_BITS;
                if(trie->subtries[radix0] == nullptr){
                    trie->subtries[radix0] = new Trie();
                }
                trie = trie->subtries[radix0];
            }
            key++;
        }
        trie->value = value;
    }

    T get(const char* key){
        Trie* trie = this;
        while(key[0] != '\0'){
            char c = key[0];
            for(unsigned int i = 0; i < steps_in_byte; i++){
                int radix0 = c & radix_mask;
                c = c >> RADIX_BITS;
                trie = trie->subtries[radix0];
            }
            key++;
        }
        return trie->value;
    }
};

