#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <getopt.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>

#define	CHECK_ALLOC(p) if(p == NULL) { perror(__func__); exit(EXIT_FAILURE); }

typedef struct _list {
     char           *word;
     struct _list   *next;
} LIST;


extern LIST *list_new(void);
extern bool list_find(LIST *list, char *wanted);
extern LIST *list_new_item(char *word);
extern LIST *list_add(LIST *list, char *word);


