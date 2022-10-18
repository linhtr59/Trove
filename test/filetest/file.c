//recursively traverse the directories and find files based off requirements
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
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <ctype.h>

// PREPROCESSOR CONSTANTS
#define	OPTION_LIST "bruf:l:"
#define DEFAULT_VALUE 4
#define DEFAULT_NAME "/tmp/trove"
#define _POSIX_C_SOURCE     200809L
#define	CHECK_ALLOC(p) if(p == NULL) { perror(__func__); exit(EXIT_FAILURE); }


void file_reader(char *filename){
    //creating a linkedlist of all valid words in the file 
    // LIST *wordlist = list_new();

    //creating a hashmap mapping filename to the linkedlist containing all valid words in file
    // HASHTABLE *hashtable = hashtable_new();
    //open file for reading
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "File does not exist or cannot be opened '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[BUFSIZ];
    size_t got;

    while((got = fread(line, 1, sizeof line, file)) >0 ){
        int length = 0;
        for (int i =0; i < BUFSIZ; i++){
            //IFF ALPHANUMERIC CHARACTER DETECTED IN WORD, INCREMENT CURRENT SIZE
            if(isalnum(line[i])){
                length++;
                continue;
            }

            //IFF A NON ALPHANUM CHARACTER IS DETECTED AND THE WORD STILL HAD NOT EXCEED MINIMUM LENGTH, RESET THE CURRENT SIZE
            else if(!isalnum(line[i]) && length < DEFAULT_VALUE){
                length = 0;
                continue;
            }
            

            //IFF WORD MEET REQUIREMENT, STORE IT INTO THE LINKED LIST OF WORDS
            else if(!isalnum(line[i]) && length >= DEFAULT_VALUE){
                char *word_content = malloc(sizeof(char) * (length +1));
                for (int j = 0; j < length; j++){
                    word_content[j] = line[i - length + j];
                    word_content[length] = '\0';
                }

                length = 0;
                printf ("%s\n", word_content);
             }
        }
    }
    fclose(file);
}


//RECURSIVELY TRAVERSE ALL DIRECTORIES AND ITS SUBDIRECTORIES 
void scan_directory (char *dirname){
    char pathname[MAXPATHLEN]; //name of path REGARDLESS of whether its full or relative
    char absolute_path[MAXPATHLEN];//absolute pathname of a file

    DIR* dir= opendir(dirname);
    struct dirent* dp;

    //report error if directory cannot be opened
    if (dir == NULL){
        perror("no directory");
        exit(EXIT_FAILURE);
    }

    //read directory until we reach singular file / end of directory    
    while((dp = readdir(dir)) != NULL){  
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }


        struct stat  stat_buffer; //stat for info about directories
        struct stat  *stat_pointer = &stat_buffer;

        // //if a directory contain a fullpath name then convert it to absolute pathnames
        sprintf(pathname, "%s/%s", dirname, dp->d_name); 
        realpath(pathname, absolute_path);


        //ensures path can be accessed
        if (stat(absolute_path, stat_pointer) != 0){
            perror(absolute_path);
            exit(EXIT_FAILURE);
        }

        //if the "file" is a directory, recursively search that directory again
        else if(S_ISDIR(stat_pointer->st_mode)){
            printf("reading directory: %s\n", pathname);
            scan_directory(pathname); //recrusive
        }

        //if file is reg file, pass that to file_reader function for processing
        else if(S_ISREG(stat_pointer->st_mode)){
            printf("finding words in: %s\n", pathname);
            file_reader(pathname);
        }
        else{
            printf("\t%s is unknown\n", pathname);
        }
    }
    
    closedir(dir);
}


int main(void){
    file_reader("trove-sample-data/csseduck.png");
}
