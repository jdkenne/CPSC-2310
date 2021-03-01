/*********************
Joshua Kennerly
CPSC 2310 Fall 2020
jdkenne, Lab 11
Dr. Feaster
**********************/
#include "functions.h"

int main(int argc, char** argv)
{
    printf("checking command line arguments\n");

    if (argc < 2) 
    { 
        printf("not enough arguments: ./exe filename\n"); 
        exit(-1);
    }

    FILE* fp = fopen(argv[1], "r");
    if(fp==NULL)
    {
        printf("fp did nto open\n"); 
        exit(-1);
    }
    int size = 0;
    int **mat = readFile(fp, &size);
    printMatrix(mat, size);
    int total = calculateVal(mat, size);
    printf("Total = %d", total);


    return 0;
}