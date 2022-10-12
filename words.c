//checking if words from files are valid

#include "trove.h"


int is_valid_word(char *word, int value){
    int result = 0; //intilize result to be false, change if meet conditions
    if (isalnum(*word) && sizeof(word)>= value){
        result = 1;
    }
    
}