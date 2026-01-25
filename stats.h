#ifndef STATS_H
#define STATS_H

#include "studentstructure.h"

float classAverage(struct student student[], int n);
float highestPercentage(struct student student[], int n);
float lowestPercentage(struct student student[], int n);
void gradeDistribution(struct student student[], int n);

#endif
