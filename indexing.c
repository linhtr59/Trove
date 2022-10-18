#define _POSIX_C_SOURCE     200809L
#define	HASHTABLE_SIZE		997

#include "trove.h"

typedef struct _list {
     char           *string;
     struct _list   *next;
} LIST;


//  WE DEFINE A HASHTABLE AS A (WILL BE, DYNAMICALLY ALLOCATED) ARRAY OF LISTs
typedef	LIST * HASHTABLE;

//  'CREATE' A NEW, EMPTY LIST - JUST A NULL POINTER
LIST *list_new(void)
{
    return NULL;
}


LIST *list_new_item(char *newstring)
{
    LIST *new       = calloc(1, sizeof(LIST) );
    CHECK_ALLOC(new);
    new->string     =  strdup(newstring);
    CHECK_ALLOC(new->string);
    new->next       =  NULL;
    return new;
}

//  ADD A NEW (STRING) ITEM TO AN EXISTING LIST
LIST *list_add(LIST *list, char *newstring)
{
    if(list_find(list, newstring)) {            // only add each item once
        return list;
    }
    else {                                      // add new item to head of list
        LIST *new   = list_new_item(newstring);
        new->next   = list;
        return new;
    }
}



uint32_t hash_string(char *string)
{
    uint32_t hash = 0;

    while(*string != '\0') {
        hash = hash*33 + *string;
        ++string;
    }
    return hash;
}

//  ALLOCATE AND INITIALISE SPACE FOR A NEW HASHTABLE (AN ARRAY OF LISTS)
HASHTABLE *hashtable_new(void)
{
    HASHTABLE   *new = calloc(HASHTABLE_SIZE, sizeof(LIST *));

    CHECK_ALLOC(new);
    return new;
}

//  ADD A NEW STRING TO A GIVEN HASHTABLE
void hashtable_add(HASHTABLE *hashtable, char *string)
{
    uint32_t h   = hash_string(string) % HASHTABLE_SIZE;    // choose list

    hashtable[h] = list_add(hashtable[h], string);
}

//  DETERMINE IF A REQUIRED STRING ALREADY EXISTS IN A GIVEN HASHTABLE
bool hashtable_find(HASHTABLE *hashtable, char *string)
{
    uint32_t h	= hash_string(string) % HASHTABLE_SIZE;     // choose list

    return list_find(hashtable[h], string);
}