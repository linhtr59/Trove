
#include "trove.h"

#define LINE_SIZE 100


void read_file(char filename[]){
    FILE *file = fopen(filename, "r");

    if(file == NULL) {
        fprintf(stderr, "cannot open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    char line[LINE_SIZE];

    // Reading file line by line and putting contents into array of structures
    while(fgets(line, sizeof line, file) != NULL){
        printf("Line: %s\n", line);
    }
}

void build(char filename[]) {
    FILE *fp = opener(filename);
    read_file(fp);
}