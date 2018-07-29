#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "trie_16.h"

#include "../dic.c"

void* get_pointer_from_trie_128_fast(char* key, Trie trie){
    while(key[0] != '\0'){
        trie=trie[(int)*key];
        key++;
    }
    return trie[0];
}

int main()
{
    Trie test_trie = new_trie();
    char* test_string = "test passed";
    char* test_key = "some_key";
    put_pointer_to_trie(test_key, test_string, test_trie);
    printf("%s\n", get_pointer_from_trie(test_key, test_trie));
    delete_trie(test_trie);

    time_t start = time(NULL);

    Trie mass_test_trie = new_trie();
    for(int j = 0; j < 10000; j++){
        for(int i = 0; i < dic_length; i++){
            put_pointer_to_trie(dic[i], dic[i], mass_test_trie);
        }
    }

    printf("Writing: %.2f\n", (double)(time(NULL) - start));
    start = time(NULL);

    for(int j = 0; j < 10000; j++){
        for(int i = 0; i < dic_length; i++){
            char* back = get_pointer_from_trie(dic[i], mass_test_trie);
            if(back != dic[i]){
                printf("error: %s != %s\n", back, dic[i]);
            }
        }
    }

    printf("Reading: %.2f\n", (double)(time(NULL) - start));

    delete_trie(mass_test_trie);
    return 0;
}
