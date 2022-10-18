#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "trove.h"
#define HASHTABLE_SIZE 10000


//HASHING FUNCTIONS - RANDOM FROM WORKSHOP 7
uint32_t hash_string(char *filename)
{
    //same filename map to the same index 
    uint32_t hash = 0;

    while(*filename != '\0') {
        hash = hash*33 + *filename;
        ++filename;
    }
    return hash;
}

void hashtable_new(void){
    HASHTABLE *new = calloc(HASHTABLE_SIZE, sizeof(INDEXFILE *));
    CHECK_ALLOC(new);
}




//ADDING NEW FILE TO HASHTABLE 
void hashtable_add(HASHTABLE *hashtable, char *filename, LIST *word){
    
    int index = hash_string(filename) % HASHTABLE_SIZE; //hash code of filename

    // while(hashtable[index] != NULL && hashtable[index]->filename != -1){
    //     ++index; //if space is occupied, move to kext space
    //     index %= HASHTABLE_SIZE;
    // }


    hashtable[index]->filename = filename;
    hashtable[index]->words = word;
}



//SEARCHING HASHTABLE BY FILENAME --> USEFUL FOR REMOVE 
INDEXFILE *hashtable_search(HASHTABLE *hashtable, char *filename){
    int index = hash_string(filename);
    while(hashtable[index]!= NULL){
        if (hashtable[index]->filename == filename){
            return hashtable[index];
        }

        ++index;
        index %= HASHTABLE_SIZE;
    }
    return NULL;
}






