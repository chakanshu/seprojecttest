#include <string.h>
#include "studentstructure.h"

void GradeFunction(int total, char grade[]){
    if(total >= 90){
        strcpy(grade, "O ");
    }
    else if(total >= 85){
        strcpy(grade, "A+");
    }
    else if(total >= 75){
        strcpy(grade, "A ");
    }
    else if(total >= 65){
        strcpy(grade, "B+");
    }
    else if(total >= 60){
        strcpy(grade, "B ");
    }
    else if(total >= 55){
        strcpy(grade, "C ");
    }
    else if(total >= 50){
        strcpy(grade, "D ");
    }
    else{
        strcpy(grade, "F ");
    }
}

int GradePoint(char grade[]){
    if(strcmp(grade, "O ") == 0) return 10;
    if(strcmp(grade, "A+") == 0) return 9;
    if(strcmp(grade, "A ") == 0) return 8;
    if(strcmp(grade, "B+") == 0) return 7;
    if(strcmp(grade, "B ") == 0) return 6;
    if(strcmp(grade, "C ") == 0) return 5;
    if(strcmp(grade, "D ") == 0) return 4;
    return 0;
}