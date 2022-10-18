// GLOBAL INCLUDES
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>


// PREPROCESSOR CONSTANTS
#define	OPTION_LIST "bruf:l:"
#define DEFAULT_VALUE 4
#define DEFAULT_NAME "/tmp/trove"
#define _POSIX_C_SOURCE     200809L
#define	CHECK_ALLOC(p) if(p == NULL) { perror(__func__); exit(EXIT_FAILURE); }


//our hashtable will essentially be like an array of filename: word key value pairds
typedef struct _list {
     char           *word;
     struct _list   *next;
}LIST;


typedef struct _index_file{
    char *filename;
    struct _list *words;
}INDEXFILE;



typedef INDEXFILE * HASHTABLE;


// GLOBAL FUNCTIONS

extern void build(int argc, char *argv[], HASHTABLE hashtable, int word_length);
extern void scan_directory (char *dirname);
extern bool is_valid_word(char *word, int value);

extern LIST *list_new(void);
extern bool list_find(LIST *list, char *wanted);
extern LIST *list_new_item(char *word);
extern LIST *list_add(LIST *list, char *word);
extern void list_remove(LIST *list, char *word);
extern void list_print(LIST *list);




extern HASHTABLE *hashtable_new(void);
extern void hashtable_add(HASHTABLE *hashtable, char *filename, LIST *word);
extern INDEXFILE *hashtable_search(HASHTABLE *hashtable, char *filename);
extern void hashtable_print(HASHTABLE *hashtable);

//GLOBAL VARIABLES
extern int word_length;
