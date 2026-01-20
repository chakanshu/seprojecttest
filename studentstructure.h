#ifndef STUDENTSTRUCTURE_H
#define STUDENTSTRUCTURE_H

struct subject {
    int minor;
    int major;
    char grade[5];
};

struct student {
    char id[20];
    char name[50];
    struct subject subjects[5];
    char status[3]; // PASS/FAIL
    float percentage;
    float cgpa;
};

#endif
