#include "trove.h"


void usage(char *argv0){
//report error in commandline processing
    fprintf(stderr, "Usage: %s [-f trovefile] word or %s [-f trovefile] [-b|-r |-u] [-l length] filelist",
                             argv0, argv0);
    exit(EXIT_FAILURE);
}



int main(int argc, char *argv[]){
    char *trovefile = DEFAULT_NAME;
    char *filelist = NULL;
    char *word = NULL;
    int word_length = DEFAULT_VALUE; //default length of word

    bool buildFlag = false;


    // HASHTABLE hashtable = hashtable_new(); // creating new empty hashtable to be built upon


    int option = 0;
    opterr	= 0;

    if(argc <= 0 || argc >5){ // Display program's usage
        usage(argv[0]);
    }
    else if(argc == 3){ // if given first prompt, assign last commandline argument to be the word to find
        word = argv[argc-1];
    }


    else if(argc > 3){ // if not first prompt, assign last commandline argument to be the filelist
        filelist = argv[argc -1];
    }

    
    while ((option = getopt(argc, argv, OPTION_LIST))!=-1){
        switch(option){
            //provided name of trove file
            case 'f':

                trovefile = strdup(optarg);

                printf("File name %s\n", trovefile);


            //building trove file
            case 'b': 
               printf("building trove file\n");
               buildFlag = true;
            
        
            //remove files
            case 'r':
                printf("removing file\n");

            //update files
            case 'u':
                printf("updating file\n");


            //appending word length to trove file
            case 'l':
                word_length = atoi(optarg);
                printf("adding n words to trove\n");

            //invalid cmd arguments option provided 
            default:
                argc = -1;
        }
    }

    argc  -= optind;
    argv  += optind;


    //determining what functions to be called. 

    if (buildFlag){
        build(argc, argv, hashtable, word_length);
    }

}
