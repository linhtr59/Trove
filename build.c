//build a trove file 


#include "trove.h"


void build(char *trovefile){
    FILE *fp;
    fp = fopen(trovefile ,"r+"); //create new trovefile.txt for reading and writing

    if (fp == NULL) {
        fprintf(stderr, "cannot open file or file dont exist\n");
        exit(EXIT_FAILURE);
    }


    //using fwrite to write structure to file


}