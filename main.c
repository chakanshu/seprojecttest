/*
Completed 
Structures to represent student data 
Grading based on percentage
display percentage and cgpa
display in tabular format
modular programming (20/01/2026 16:47)

To Do
Class average percentage
Highest and lowest percentage 
number of students in each category
error handling

Errors
it shows pass for everyone
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
    printf("+---------------------------------------------------------------------+");
    printf("\n| ID   | m1 M1 m2 M2 m3 M3 m4 M4 m5 M5 G1 G2 G3 G4 G5 P/F  %%     CGPA |\n");
    printf("+---------------------------------------------------------------------+\n");
    for(int i = 0; i < n; i++){
        int totalMarks = 0;
        int cgpaSum = 0;
        int failFlag = 0;

        printf("| %s | ", student[i].id);

        for(int j = 0; j < 5; j++){
            printf("%d %d ",
                   student[i].subjects[j].minor,
                   student[i].subjects[j].major);
        }

        for(int j = 0; j < 5; j++){
            int subjectTotal =
                student[i].subjects[j].minor +
                student[i].subjects[j].major;

            GradeFunction(subjectTotal, student[i].subjects[j].grade);

            if(strcmp(student[i].subjects[j].grade, "F") == 0){
                failFlag = 1;
            }

            cgpaSum += GradePoint(student[i].subjects[j].grade);
            totalMarks += subjectTotal;

            printf("%s ", student[i].subjects[j].grade);
        }

        student[i].percentage = totalMarks / 5.0;
        student[i].cgpa = cgpaSum / 5.0;

        if(failFlag){
            strcpy(student[i].status, "FAIL");
        } else {
            strcpy(student[i].status, "PASS");
        }

        printf("%s %.2f %.2f |\n",
               student[i].status,
               student[i].percentage,
               student[i].cgpa);
    }

    printf("+---------------------------------------------------------------------+");
    return 0;
}
