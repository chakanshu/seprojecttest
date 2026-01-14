#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subject {
    int minor;
    int major;
};

struct student {
    char id[20];
    char name[50];
    struct subject subjects[5];
};

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

int main(int argc, char *argv[]){
    FILE *fptr;
    int count = 0;
    char c;
    char filename[50] = "Studentdata.txt";

    if(argc > 1 && strcmp(argv[1], "2") == 0){
        strcpy(filename, "StudentdataInvalid.txt");
    }

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

    int n = count;
    struct student student[n];
    printf("");
    printf("\nID   m1 M1 m2 M2 m3 M3 m4 M4 m5 M5 G1 G2 G3 G4 G5 P/F  %%     CGPA\n\n");

    for(int i = 0; i < n; i++){
        fscanf(fptr, "%s %s", student[i].id, student[i].name);

        for(int j = 0; j < 5; j++){
            fscanf(fptr, "%d %d",
                   &student[i].subjects[j].minor,
                   &student[i].subjects[j].major);
        }
    }

    fclose(fptr);

    for(int i = 0; i < n; i++){
        int totalMarks = 0;
        int failFlag = 0;
        int cgpaSum = 0;

        printf("%s ", student[i].id);
        // Original line to print names 
        // printf("%s %s ", student[i].id, student[i].name);

        for(int j = 0; j < 5; j++){
            int subjectTotal =
                student[i].subjects[j].minor +
                student[i].subjects[j].major;

            printf("%d %d ",/*subjectTotal,*/  student[i].subjects[j].minor, student[i].subjects[j].major);
        }

        for(int j = 0; j < 5; j++){
            int subjectTotal =
                student[i].subjects[j].minor +
                student[i].subjects[j].major;

            char grade[3];
            GradeFunction(subjectTotal, grade);

            if(strcmp(grade, "F") == 0){
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
