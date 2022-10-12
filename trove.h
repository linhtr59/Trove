
// GLOBAL INCLUDES
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <sys/param.h>

// PREPROCESSOR CONSTANTS
#define	OPTION_LIST "bf:l:,ru"
#define DEFAULT_VALUE 4
#define DEFAULT_NAME "/tmp/trove"

// GLOBAL FUNCTIONS
extern void build();
extern void update();
extern void remove();
extern int is_valid_word();

