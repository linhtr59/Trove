//recursively traverse the directories and find files based off requirements

#include "trove.h"

void list_file (char *dirname){

    char *fullpath; //name of absolute path

    DIR* dir= opendir("dirname");
    struct dirent* dp;

    if (dir == NULL){
        perror("no directory");
        exit(EXIT_FAILURE);
    }

    
    while((dp = readdir(dir)) != NULL){  
        struct stat  stat_buffer;
        struct stat  *pointer = &stat_buffer;
        sprintf(fullpath, "%s/%s", dirname, dp->d_name );

        if(stat(fullpath, pointer) != 0) {
             perror("error");
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
 
    size_t total = 0; //keeps track of total no of word in file
   
    // Reading file line by line and putting contents into array of structures
   
}




        // char cmin[MAX_CHAR];
        // char chour[MAX_CHAR];
        // char cday[MAX_CHAR];
        // char cmonth[MAX_CHAR];
        // char cdate[MAX_CHAR];
        // char cmd[41];

        // while (isspace(lines[j]))
        // { // if the character is a white space, continute to examine next character
        //     j++;
        // }

        // if (lines[j] != '#')
        // { // if the first nons-space character is not a # then store data into struct
        //     sscanf(lines, "%s %s %s %s %s %s",
        //            cmin, chour, cday, cmonth, cdate, cmd);
        //            printf("%s \n", lines);

        //     strcpy(crontab_data[line].minute, cmin);
        //     strcpy(crontab_data[line].hour, chour);
        //     strcpy(crontab_data[line].day, cday);
        //     strcpy(crontab_data[line].month, cmonth);
        //     strcpy(crontab_data[line].date, cdate);
        //     strcpy(crontab_data[line].command, cmd);
        //     line++;
        //     file_size++;
        // }



