#ifndef VALIDATION_H
#define VALIDATION_H

#include "studentstructure.h"

int isValidID(char id[]);
int isDuplicateID(struct student student[], int n, int index);
int isValidMarks(struct student *s);

#endif
