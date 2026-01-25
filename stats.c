#include <stdio.h>
#include <string.h>
#include "stats.h"

float classAverage(struct student student[], int n){
    float sum = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        if(strcmp(student[i].status, "ERR") != 0){
            sum += student[i].percentage;
            count++;
        }
    }
    return (count == 0) ? 0 : sum / count;
}

float highestPercentage(struct student student[], int n){
    float max = -1;
    for(int i = 0; i < n; i++){
        if(strcmp(student[i].status, "ERR") != 0 && student[i].percentage > max){
            max = student[i].percentage;
        }
    }
    return max;
}

float lowestPercentage(struct student student[], int n){
    float min = 101;
    for(int i = 0; i < n; i++){
        if(strcmp(student[i].status, "ERR") != 0 && student[i].percentage < min){
            min = student[i].percentage;
        }
    }
    return min;
}

void gradeDistribution(struct student student[], int n){
    int O=0, Aplus=0, A=0, Bplus=0, B=0, C=0, D=0, F=0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            char *g = student[i].subjects[j].grade;
            if(strcmp(g,"O ")==0) O++;
            else if(strcmp(g,"A+")==0) Aplus++;
            else if(strcmp(g,"A ")==0) A++;
            else if(strcmp(g,"B+")==0) Bplus++;
            else if(strcmp(g,"B ")==0) B++;
            else if(strcmp(g,"C ")==0) C++;
            else if(strcmp(g,"D ")==0) D++;
            else if(strcmp(g,"F ")==0) F++;
        }
    }

    printf("\nGrade Distribution:\n");
    printf("O : %d\nA+: %d\nA : %d\nB+: %d\nB : %d\nC : %d\nD : %d\nF : %d\n",
           O, Aplus, A, Bplus, B, C, D, F);
}
