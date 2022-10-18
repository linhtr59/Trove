//build a trove file 
//trovefile will be a hashtable, mapping one word to its supposed directories
//we first intialize new empty hashtable
//we then record all the words in the filelist file into the hash tbale and then write up that index
//print the number of key and values in trove which will in turns correspond to number of unique file and number of unique word 

#include "trove.h"


char *trovefile_name = DEFAULT_NAME;
FILE *trovefile = NULL;


void change_name(char *filename){
    trovefile_name = strdup(filename);
}


//OPENING TROVE FILE AND DECOMPRESS
void open_trove(void){
    char *cmd = (char *)malloc(sizeof(char) * ARG_MAX);
    CHECK_ALLOC(cmd);
    strcpy(cmd, "zcat '");
    strcat(cmd, trovefile_name);
    strcat(cmd, "'");
    if (file_exist(trovefile_name))
    {
        trovefile = popen(cmd, "r");
    }

}


//CLOSING AND ZGIPING TROVE 
void gzip_trove(void){
    fclose(trovefile);

    char *cmd= (char *)malloc(sizeof(char) * ARG_MAX);
    CHECK_ALLOC(cmd);

    strcpy(cmd, "gzip -9 '");
    strcat(cmd, trovefile_name);
    strcat(cmd, "'");
    system(cmd);
    strcpy(cmd, "mv '");
    strcat(cmd, trovefile_name);
    strcat(cmd, ".gz' '");
    strcat(cmd, trovefile_name);
    strcat(cmd, "'");
    system(cmd);
}




void build(int argc, char *argv[], HASHTABLE hashtable, int word_length){
    char *filelist = argv[argc -1];


    trovefile = fopen(trovefile_name, "w+"); //opening trovefile for writing;
    fseek(trovefile, 0, SEEK_SET);

    gzip_trove();
}
