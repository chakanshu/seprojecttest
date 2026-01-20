#ifndef STUDENTSTRUCTURE_H
#define STUDENTSTRUCTURE_H

struct subject {
    int minor;
    int major;
};

struct student {
    char id[20];
    char name[50];
    struct subject subjects[5];
};

#endif
