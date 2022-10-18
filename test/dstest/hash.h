// GLOBAL INCLUDES
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <getopt.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>

#ifndef HASH_H
#define HASH_H

#include "list.h"


typedef struct _index_file{
    char *filename;
    struct _list *words;
}INDEXFILE;



typedef INDEXFILE * HASHTABLE;


extern HASHTABLE *hashtable_new(void);
extern INDEXFILE *hashtable_search(HASHTABLE *hashtable, char *filename);
extern void hashtable_add(HASHTABLE *hashtable, char *filename, LIST *word);
extern void hashtable_print(HASHTABLE *hashtable);

#endif