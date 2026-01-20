/*
Completed 
Structures to represent student data 
Grading based on percentage
display percentage and cgpa
display in tabular format

To Do
Class average percentage
Highest and lowest percentage 
number of students in each category

error handling
modular programming
*/

#include <stdio.h>
#include <string.h>
#include "studentstructure.h"
#include "grade.h"
#include "fileio.h"

int main(int argc, char *argv[]){
    char filename[50] = "Studentdata.txt";

    if(argc > 1 && strcmp(argv[1], "2") == 0){
        strcpy(filename, "StudentdataInvalid.txt");
    }

    struct student student[100];
    int n = readStudents(student, filename);

    printf("");
    printf("\nID   m1 M1 m2 M2 m3 M3 m4 M4 m5 M5 G1 G2 G3 G4 G5 P/F  %%     CGPA\n\n");

    for(int i = 0; i < n; i++){
        int totalMarks = 0;
        int failFlag = 0;
        int cgpaSum = 0;

        printf("%s ", student[i].id);
        // Original line to print names 
        // printf("%s %s ", student[i].id, student[i].name);

        for(int j = 0; j < 5; j++){
            printf("%d %d ",
                   student[i].subjects[j].minor,
                   student[i].subjects[j].major);
        }

        for(int j = 0; j < 5; j++){
            int subjectTotal =
                student[i].subjects[j].minor +
                student[i].subjects[j].major;

            char grade[3];
            GradeFunction(subjectTotal, grade);

            if(strcmp(grade, "F ") == 0){
                failFlag = 1;
            }

            cgpaSum += GradePoint(grade);
            totalMarks += subjectTotal;

            printf("%s ", grade);
        }

        float percentage = totalMarks / 5.0;
        float cgpa = cgpaSum / 5.0;

        if(failFlag){
            printf("FAIL ");
        } else {
            printf("PASS ");
        }

        printf("%.2f %.2f\n", percentage, cgpa);
    }

    return 0;
}
