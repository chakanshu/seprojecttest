#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *fptr;
    int count, buffer;
    char c;
    buffer = 100;
    fptr = fopen("Studentdata.txt", "r");
    for (c = getc(fptr); c != EOF; c = getc(fptr)) {
        if (c == '\n') {
            count++;
        }
    }

    int n = count;
    int id[n];
    char name[n];
    int marks[n][5];


    if(fptr == NULL){
        printf("Add something to the file to print it lol \n");
        exit(1);
    }
    
    /*
    while(fscanf(fptr, "%d", &num) == 1){
        printf("%d\n", num);
    }
    */

    for(int i = 0; i <= n; i++){
        printf("%d\n", i);
        if (sscanf(buffer, "%d %c %d %d %d %d %d", id, name, marks[i][1], 
                                                             marks[i][2], 
                                                             marks[i][3], 
                                                             marks[i][4], 
                                                             marks[i][1]) == 2) {
            /*printf("Name: %s, Age: %d\n", id, name, marks[i][1], 
                                                    marks[i][2], 
                                                    marks[i][3], 
                                                    marks[i][4], 
                                                    marks[i][1]);
                                                    */
        } else {
            fprintf(stderr, "Error parsing line: %s", buffer);
        }
    }

    fclose(fptr);

    printf("%d\n", count);

    for(int i = 0; i <= n; i++){
        printf("%d %c %d %d %d %d %d \n", id, name, marks[i][1], 
                                                    marks[i][2], 
                                                    marks[i][3], 
                                                    marks[i][4], 
                                                    marks[i][1]);
    }
    
    return 0;
}