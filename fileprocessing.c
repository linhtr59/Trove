//recursively traverse the directories and find files based off requirements

#include "trove.h"

void list_file (char *dirname){
    char *progname;
    char *fullpath; //name of absolute path

    DIR* dir= opendir("dirname");
    struct dirent* dp;

    if (dir == NULL){
        perror(progname);
        exit(EXIT_FAILURE);
    }

    
    while((dp = readdir(dir)) != NULL){  
        struct stat  stat_buffer;
        struct stat  *pointer = &stat_buffer;
        sprintf(fullpath, "%s/%s", dirname, dp->d_name );

        if(stat(fullpath, pointer) != 0) {
             perror( progname );
        }
        // else if( S_ISDIR( pointer->st_mode )) {
        //     printf( "%s is a directory\n", fullpath );
        // }
        else if( S_ISREG( pointer->st_mode )) {
            file_reader(fullpath); //passing the currently traversed file to open and read
            printf( "%s is a regular file\n", fullpath );
        
        }
        else {
            printf( "%s is unknown!\n", fullpath );
        }
    }
    
    closedir(dir);
}




void file_reader(char filename[]){
    FILE *file = fopen(filename, "r");

    if(file == NULL) {
        fprintf(stderr, "File does not exist or cannot be opened '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char line[LINE_SIZE];
    // Reading file line by line and putting contents into array of structures
    while(fgets(line, sizeof line, file) != NULL){
        printf("Line: %s\n", line);
        //do something here with word.c
    }
}



