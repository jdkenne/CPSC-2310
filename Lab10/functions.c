/*********************
Joshua Kennerly
CPSC 2310 Fall 2020
jdkenne
Dr. Feaster
**********************/
#include "functions.h"

int printReturn(int a, int b, int action) {
    int x = action == 1 ? a==b: action == 2 ? a<b: action == 3 ? a>b: -50000;
    return x;
}