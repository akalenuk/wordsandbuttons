#pragma once

#include <array>
#include <vector>

namespace Trie {
    template <unsigned int RADIX_BITS> 
    struct ConstantsFor {
        static_assert(RADIX_BITS == 1 || RADIX_BITS == 2 || RADIX_BITS == 4 || RADIX_BITS == 8, "Radix size should be power of 2 and not bigger than 8");
        constexpr static unsigned int mask(unsigned int radix_bits){
            return (radix_bits == 1) ? 1 : (1 + (mask(radix_bits - 1) << 1));
        }
        constexpr static unsigned int pow_of_2(unsigned int exp){
            return (exp == 1) ? 2 : (2 * pow_of_2(exp - 1));
        }
        constexpr static unsigned int radix_mask = mask(RADIX_BITS);
        constexpr static unsigned int steps_in_byte = 8 / RADIX_BITS;
        constexpr static unsigned int subtrie_size = pow_of_2(RADIX_BITS);
    };



    template <unsigned int RADIX_BITS> 
    struct Set : public ConstantsFor <RADIX_BITS>{
        std::array<Set*, ConstantsFor<RADIX_BITS>::subtrie_size> subtries{nullptr};
        unsigned int elements_counter = 0u;

        ~Set(){
            for(auto trie : subtries)
                if(trie != nullptr)
                    delete trie;
        }

        void store(const char* key){
            Set* trie = this;
            while(key[0] != '\0'){
                for(auto i = 0u; i < ConstantsFor<RADIX_BITS>::steps_in_byte; ++i){
                    const int shifted_c = key[0] >> (8 - (i + 1) * RADIX_BITS);
                    const int radix0 = shifted_c & ConstantsFor<RADIX_BITS>::radix_mask;
                    if(trie->subtries[radix0] == nullptr){
                        trie->subtries[radix0] = new Set();
                    }
                    trie = trie->subtries[radix0];
                }
                key++;
            }
            ++trie->elements_counter;
        }

        bool contains(const char* key){
            Set* trie = this;
            while(key[0] != '\0'){
                for(auto i = 0u; i < ConstantsFor<RADIX_BITS>::steps_in_byte; ++i){
                    const int shifted_c = key[0] >> (8 - (i + 1) * RADIX_BITS);
                    const int radix0 = shifted_c & ConstantsFor<RADIX_BITS>::radix_mask;
                    if (trie->subtries[radix0] == nullptr)
                        return false;
                    trie = trie->subtries[radix0];
                }
                key++;
            }
            return true;
        }



        static void fill_vector_sorted(Set* trie, std::vector<std::string>& sorted) {
            std::string key;
            key.resize(256);
            fill_vector_sorted(trie, sorted, key, 0);
        }

private:
        static void fill_vector_sorted(Set* trie, std::vector<std::string>& sorted, std::string& key, int depth) {
            const auto byte_idx = depth / ConstantsFor<RADIX_BITS>::steps_in_byte;
            const auto radix_idx = depth % ConstantsFor<RADIX_BITS>::steps_in_byte;
            for(auto i = 0u; i < trie->elements_counter; ++i) {
                sorted.emplace_back(key.begin(), key.begin() + byte_idx);
            }
            for(auto i = 0u; i < ConstantsFor<RADIX_BITS>::subtrie_size; ++i) {
                if(trie->subtries[i] != nullptr) {
                    auto c = key[byte_idx];
                    c  >>= ((ConstantsFor<RADIX_BITS>::steps_in_byte - i) * RADIX_BITS);
                    c <<= RADIX_BITS;
                    c += i;
                    c <<= (ConstantsFor<RADIX_BITS>::steps_in_byte - i - 1) * RADIX_BITS;
                    key[byte_idx] = c;
                    fill_vector_sorted(trie, sorted, key, depth + 1);
                }
            }
        }
/*
        static void fill_vector_sorted(Set* trie, std::vector<std::string>& sorted, const std::vector<char>& long_key = std::vector<char>() ) {
            if(trie->elements_counter > 0) {
                std::string short_key;
                for(auto j = 0u; j < long_key.size() / ConstantsFor<RADIX_BITS>::steps_in_byte; ++j) {
                    char c = 0;
                    for(auto k = 0u; k < ConstantsFor<RADIX_BITS>::steps_in_byte; ++k) {
                        c <<= RADIX_BITS;
                        c |= long_key[j * ConstantsFor<RADIX_BITS>::steps_in_byte + k];
                    }
                    short_key += c;
                }
                for(auto i = 0u; i < trie->elements_counter; ++i)
                    sorted.push_back(short_key);
            }
            for(auto i = 0u; i < ConstantsFor<RADIX_BITS>::subtrie_size; ++i) {
                if(trie->subtries[i] != nullptr) {
                    std::vector<char> new_long_key(long_key.begin(), long_key.end());
                    new_long_key.push_back(static_cast<char>(i));
                    fill_vector_sorted(trie->subtries[i], sorted, new_long_key);
                }
            } 
        }*/
    };



    template <class T, unsigned int RADIX_BITS> 
    struct Map : public ConstantsFor <RADIX_BITS>{
        std::array<Map*, ConstantsFor<RADIX_BITS>::subtrie_size> subtries{nullptr};
        T value;

        ~Map(){
            for(auto trie : subtries){
                if(trie != nullptr){
                    delete trie;
                }
            }
        }

        void store(const char* key, T value){
            Map* trie = this;
            while(key[0] != '\0'){
                char c = key[0];
                for(auto i = 0; i < ConstantsFor<RADIX_BITS>::steps_in_byte; ++i){
                    const int radix0 = c & ConstantsFor<RADIX_BITS>::radix_mask;
                    c = c >> RADIX_BITS;
                    if(trie->subtries[radix0] == nullptr){
                        trie->subtries[radix0] = new Map();
                    }
                    trie = trie->subtries[radix0];
                }
                key++;
            }
            trie->value = value;
        }

        std::pair<bool, T> retrieve(const char* key){
            Map* trie = this;
            while(key[0] != '\0'){
                char c = key[0];
                for(auto i = 0; i < ConstantsFor<RADIX_BITS>::steps_in_byte; ++i){
                    const int radix0 = c & ConstantsFor<RADIX_BITS>::radix_mask;
                    if (trie->subtries[radix0] == nullptr)
                        return {false, T()};
                    c = c >> RADIX_BITS;
                    trie = trie->subtries[radix0];
                }
                key++;
            }
            return {true, trie->value};
        }
    };
}

