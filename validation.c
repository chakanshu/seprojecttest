#include <string.h>
#include <ctype.h>
#include "validation.h"

int isValidID(char id[]){
    for(int i = 0; id[i] != '\0'; i++){
        if(!isalnum(id[i])){
            return 0;
        }
    }
    return 1;
}

int isDuplicateID(struct student student[], int n, int index){
    for(int i = 0; i < n; i++){
        if(i != index && strcmp(student[i].id, student[index].id) == 0){
            return 1;
        }
    }
    return 0;
}

int isValidMarks(struct student *s){
    for(int i = 0; i < 5; i++){
        if(s->subjects[i].minor < 0 || s->subjects[i].minor > 40)
            return 0;
        if(s->subjects[i].major < 0 || s->subjects[i].major > 60)
            return 0;
    }
    return 1;
}
