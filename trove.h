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
#define	OPTION_LIST "brul::f"
#define _POSIX_C_SOURCE     200809L
#define	CHECK_ALLOC(p) if(p == NULL) { perror(__func__); exit(EXIT_FAILURE); }
#define HASHTABLE_SIZE 10000


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

//BUILDING FUNCTIONS 
extern HASHTABLE *trove_to_hashtable(void);
extern void change_name(char *filename);
extern char *wordlist_read(LIST *wordlist);
extern char *hashtable_read(HASHTABLE *hashtable);
extern void build(int argc, char *argv[]);
extern void trove_write(HASHTABLE *hashtable);


//FILE PROCESSING FUNCTIONS TO CONSTRUCT HASHTABLES
extern void scan_directory (char *dirname, HASHTABLE *hashtable, LIST *wordlist);
extern void file_reader(char *filename, HASHTABLE *hashtable, LIST *wordlist);



//LIST FUNCTIONS
extern LIST *list_new(void);
extern bool list_find(LIST *list, char *wanted);
extern LIST *list_new_item(char *word);
extern LIST *list_add(LIST *list, char *word);
extern void list_remove(LIST *list, char *word);
extern void list_print(LIST *list);



//HASHTABLE FUNCTIONS
extern HASHTABLE *hashtable_new(void);
extern void hashtable_add(HASHTABLE *hashtable, char *filename, LIST *word);
extern void hashtable_remove(HASHTABLE *hashtable, char *target);
extern LIST *hashtable_findword(HASHTABLE *hashtable, char *target);
extern void hashtable_update(HASHTABLE *hashtable1, HASHTABLE *hashtable2);
extern void hashtable_print(HASHTABLE *hashtable);


//SEARCH WORD FUNCTIONS
extern void find_word(int argc, char *argv[]);


//GLOBAL VARIABLES
extern int word_length;
extern char *trovefile;
extern char *filelist;

