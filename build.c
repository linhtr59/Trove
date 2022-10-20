
#include "trove.h"
FILE *trove_file = NULL;


//CHANGE TROVE FILE NAME
void change_name(char *filename){
    trovefile = strdup(filename);
}


//OPEN A TROVE FILE AND LOAD ITS CONTENT TO A HASHTABLE
HASHTABLE *trove_to_hashtable(void){
    HASHTABLE *hashtable = hashtable_new();
    // LIST *wordlist = list_new();
    FILE *trove_file = fopen(trovefile,"r"); //open trovefile for reading

    if (trove_file == NULL){
        perror("nani");
        exit(EXIT_FAILURE);
    }

    char *filename = malloc(sizeof(char*));
    char *words = malloc(sizeof(char*));
    char *token;
    CHECK_ALLOC(filename);
    CHECK_ALLOC(words);

    while(!feof(trove_file)){
        fscanf(trove_file, "%s %s", filename, words);
        token = strtok(words,","); //spliting words value by delimiter comma
        while (token != NULL){
            printf("%s", token);

        }
    }

    fclose(trove_file);
    return hashtable;
}




//OPENING TROVE FILE AND DECOMPRESS
FILE *open_trove(void){
    char *cmd = (char *)malloc(sizeof(char) * ARG_MAX);
    CHECK_ALLOC(cmd);
    strcpy(cmd, "zcat '");
    strcat(cmd, trovefile);
    strcat(cmd, "'");
    // trove_file = popen(cmd, "r"); //if it exists 
    return trove_file;

}


//CLOSING AND GZIPING TROVE 
void gzip_trove(void){
    fclose(trove_file);

    char *cmd= (char *)malloc(sizeof(char) * ARG_MAX);
    CHECK_ALLOC(cmd);

    strcpy(cmd, "gzip -9 '");
    strcat(cmd, trovefile);
    strcpy(cmd, "mv '");
    strcat(cmd, ".gz' '");
    strcat(cmd, trovefile);
    strcat(cmd, "'");
    system(cmd);

    free(cmd);
}



//GIVEN A HASHTABLE, RETURN A STRING REPRESENTING ALL ITS ENTRIES AS CSV VALUES
char *hashtable_read(HASHTABLE *hashtable){
    char *str = strdup(""); // starts with empty string
    char *strwordlist; //storing string from the hashtable 
    char *strfilename;

    for (int i =0; i < HASHTABLE_SIZE; i++){

        while(hashtable[i]!= NULL){
            strwordlist = strdup(hashtable[i]->words));
            strfilename = strdup(hashtable[i]->filename);

            str = (char *)realloc(str, sizeof(char) * (strlen(str) + strlen(strwordlist) + strlen(strfilename) + 3)); //plus two for space for comma and endline
            CHECK_ALLOC(str);
        }
        
    }
    return str;

}


//WRITING TROVEFILE CONTENT WITH THE HASHTABLE
void trove_write(HASHTABLE *hashtable){
    trove_file = fopen(trovefile, "w+"); 
    fseek(trove_file, 0, SEEK_SET);
    
    char *str = hashtable_read(hashtable);
    fputs(str,trove_file);

    printf("trovefile contents: %s", str);

}



//CONSTRUCTING THE HASHTABLE ENTRIES AND WRITING TO TROVEFILE
void build(int argc, char *argv[]){
    char *filelist = argv[argc -1];
    HASHTABLE *hashtable = hashtable_new();
    LIST *wordlist = list_new();
    scan_directory(filelist, hashtable, wordlist);



    //WRITING THE TROVEFILE
    printf("writing trovefile");
    trove_write(hashtable);

    gzip_trove();
    printf("compressing trovefile: %s", trovefile);
}
