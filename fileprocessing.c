//recursively traverse the directories and find files based off requirements
#include "trove.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>

bool is_valid_word(char *word, int word_length){
    char c = *word;
    int c_length = strlen(word);

    //IF WORD CHARACTER IS LESS THAN SPECIFIED VALUE
    if (c_length <= word_length){ 
        return false;
    }

    //CHECK IF EACH CHARACTER OF WORD IS ALPHANUMERIC, IF ANY ISNT, RETURN FALSE
    while(c != '\0'){
        if (!isalnum(c)){
            return false;
        }
    }
    return true;
}



void file_reader(char *filename, HASHTABLE *hashtable, LIST *wordlist){
    //open file for reading
    FILE *file = fopen(filename, "r");

    if(file == NULL) {
        fprintf(stderr, "File does not exist or cannot be opened '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    
    
    //open file for reading
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "File does not exist or cannot be opened '%s'\n", filename);
        exit(EXIT_FAILURE);
    }


    struct stat sb;
    if (stat(filename, &sb) == -1){
        perror("stat");
        exit(EXIT_FAILURE);
    }


    char *word_content = malloc(sb.st_size);
    CHECK_ALLOC(word_content);

    //reading file word by word, checking if it is a valid word and if yes adding it to the hashtable with the filename
    while (fscanf(file, "%[^-\n ] ", word_content) != EOF){
        if (is_valid_word(word_content, word_length)){
            printf("%s \n", word_content);
            list_add(wordlist, word_content);
        }
    }

    hashtable_add(hashtable, filename, wordlist);
    hashtable_print(hashtable);
    fclose(file);
}


//RECURSIVELY TRAVERSE ALL DIRECTORIES AND ITS SUBDIRECTORIES 
void scan_directory (char *dirname, HASHTABLE *hashtable, LIST *wordlist){
    char pathname[MAXPATHLEN]; //name of path REGARDLESS of whether its full or relative
    char absolute_path[MAXPATHLEN];//absolute pathname of a file

    DIR* dir= opendir(dirname);
    struct dirent* dp;

    //report error if directory cannot be opened
    if (dir == NULL){
        perror("no directory found");
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
            printf("reading directory: %s \n", pathname);
            scan_directory(pathname, hashtable, wordlist); //recrusive
        }

        //if file is reg file, pass that to file_reader function for processing
        else if(S_ISREG(stat_pointer->st_mode)){
            printf("finding word in: %s\n", pathname);
            file_reader(pathname, hashtable, wordlist);
        }
        else{
            printf("\t%s is unknown\n", pathname);
        }
    }
    
    closedir(dir);
}
