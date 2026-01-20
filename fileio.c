#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

int readStudents(struct student student[], const char *filename){
    FILE *fptr;
    int count = 0;
    char c;

    fptr = fopen(filename, "r");
    if(fptr == NULL){
        printf("Add something to the file to print it lol\n");
        exit(1);
    }

    for(c = getc(fptr); c != EOF; c = getc(fptr)){
        if(c == '\n'){
            count++;
        }
    }

    rewind(fptr);

    for(int i = 0; i < count; i++){
        fscanf(fptr, "%s %s", student[i].id, student[i].name);

        for(int j = 0; j < 5; j++){
            fscanf(fptr, "%d %d",
                   &student[i].subjects[j].minor,
                   &student[i].subjects[j].major);
        }
    }

    fclose(fptr);
    return count;
}
