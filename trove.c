#include "trove.h"


void usage(){
    printf("Usage: trove - c\n");

}

int main(int argc, char *argv[]){
    char *name = argv[argc - 1]; //name of trove file
    int length = DEFAULT_VALUE; //default length of word

    int option = 0;
    opterr	= 0;


    int isBuilding = 0; //1 if searching and 0 if trove wants to build file



    while ((option = getopt(argc, argv, OPTION_LIST))!=-1){
        switch(option){
            //building trove file
            case 'b': 
               printf("building trove file\n");
            
            //provided name of trove file
            case 'f':
                printf("provided name\n");
                if(argv[3] = name){
                    isBuilding = 1;//update usage to searching
                }

            //appending word length to trove file
            case 'l':
                printf("adding n words to trove\n");

            //remove files
            case 'r':
                printf("removing file\n");

            //update files
            case 'u':
                printf("updating file\n");

            //invalid cmd arguments option provided 
            default:
                argc = -1;
                printf(stderr,"Invalid input");
                exit(EXIT_FAILURE);


        


        }
    }


}