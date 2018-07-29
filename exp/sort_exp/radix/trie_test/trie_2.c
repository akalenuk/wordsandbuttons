#include <stdlib.h>
#include "trie_2.h"

#define RADIX 2

Trie new_trie(){
    return calloc(RADIX+1, sizeof(void*));
}

void put_pointer_to_trie(char* key, void* pointer, Trie trie){
    while(key[0] != '\0'){
        char c = key[0];
        for(int i = 0; i < 8; i++){
            int radix0 = c & 1;
            c = c >> 1;
            if(trie[radix0] == NULL){
                trie[radix0] = new_trie();
            }
            trie = trie[radix0];
        }
        key++;
    }
    trie[RADIX] = pointer;
}

void* get_pointer_from_trie(char* key, Trie trie){
    while(key[0] != '\0'){
        char c = key[0];
        for(int i = 0; i < 8; i++){
            int radix0 = c & 1;
            c = c >> 1;
            trie = trie[radix0];
        }
        key++;
    }
    return trie[RADIX];
}

void delete_trie(Trie trie){
    for(int i = 1; i < RADIX; i++){
        if(trie[i] != NULL){
            delete_trie(trie[i]);
            free(trie[i]);
        }
    }
}
