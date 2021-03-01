/*********************
Joshua Kennerly
CPSC 2310 Fall 2020
jdkenne, Lab 11
Dr. Feaster
**********************/
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

int** readFile(FILE* fp, int *size);
void printMatrix (int** mat, int num);
bool isRightDiagonal(int size, int row, int col);
bool isLeftDiagonal(int row, int col);
int calculateVal(int** mat, int size);
