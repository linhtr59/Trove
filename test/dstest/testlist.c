#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "list.h"

LIST *list_new(void){
    LIST *list = (LIST *)malloc(sizeof(LIST));
    CHECK_ALLOC(list);
    return list;
}


//FIND IF WORD EXIST IN LIST ALREADY
bool list_find(LIST *list, char *wanted){
    while(list != NULL){
        if (strcmp(list->word, wanted) == 0){
            return true;
        }
    }
    list = list->next;
    return false;
}


//ALLOCATE NEW SPACE FOR NEW LIST ITEM, TESTING SUCCESSFUL ALLOCATION
LIST *list_new_item(char *word){
    LIST *new       = calloc(1, sizeof(LIST) );
    CHECK_ALLOC(new);

    new->word = strdup(word);
    new->next = list_new();
    return new;

}

LIST *list_add(LIST *list, char *word){
    if (list_find(list, word)){
        return list;
    }
    else{
        LIST *new = list_new_item(word);
        new->next = list;
        return new;
    }
}

void list_remove(LIST *list, char *word){
    while (list->next != NULL && list->word!= NULL && word != NULL)
    {
        if (strcmp(list->word, word) == 0)
        {
            LIST *tmp = list->next;
            list->next = list->next->next;
            free(tmp);
            break;
        }
        list = list->next;
    }
}


void list_print(LIST *list)
{
    if(list != NULL) {
        while(list != NULL) {
	    printf("%s", list->word);
	    if(list->next != NULL) {
	        printf(" -> ");
            }
	    list	= list->next;
        }
	printf("\n");
    }
}
