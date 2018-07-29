#include <stdlib.h>
#include "trie_128.h"

#define RADIX 128

Trie new_trie(){
    return calloc(RADIX, sizeof(void*));
}

void put_pointer_to_trie(char* key, void* pointer, Trie trie){
    if(*key == '\0'){
        trie[0] = pointer;
    }else{
        if(trie[(int)*key] == NULL){
            trie[(int)*key] = new_trie();
        }
        put_pointer_to_trie(key+1, pointer, trie[(int)*key]);
    }
}

void* get_pointer_from_trie(char* key, Trie trie){
    if(*key == '\0'){
        return trie[0];
    }else{
        return get_pointer_from_trie(key+1, trie[(int)*key]);
    }
}

void delete_trie(Trie trie){
    for(int i = 1; i < RADIX; i++){
        if(trie[i] != NULL){
            delete_trie(trie[i]);
            free(trie[i]);
        }
    }
}
