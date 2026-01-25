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
(Fixed)it shows pass for everyone
"F " was being compared to "F" resulting in condition always being false.
*/

#include <stdio.h>
#include <string.h>
#include "studentstructure.h"
#include "grade.h"
#include "fileio.h"
#include "validation.h"
#include "stats.h"

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
        int errorFlag = 0;

        if(!isValidID(student[i].id) ||
           isDuplicateID(student, n, i) ||
           !isValidMarks(&student[i])){
            errorFlag = 1;
        }

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

            if(student[i].subjects[j].grade[0] == 'F'){
                failFlag = 1;
            }

            cgpaSum += GradePoint(student[i].subjects[j].grade);
            totalMarks += subjectTotal;

            printf("%s ", student[i].subjects[j].grade);
        }

        if(errorFlag){
            strcpy(student[i].status, "ERR");
            printf("ERR  ERR  ERR   |\n");
            continue;
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

    printf("+---------------------------------------------------------------------+\n");

    printf("\nClass Average Percentage: %.2f\n", classAverage(student, n));
    printf("Highest Percentage: %.2f\n", highestPercentage(student, n));
    printf("Lowest Percentage: %.2f\n", lowestPercentage(student, n));

    gradeDistribution(student, n);

    return 0;
}
