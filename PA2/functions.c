/***************************
* Joshua Kennerly          *
* CPSC 2310 Fall 2020      *
* jdkenne                  *
* Instructor: Dr. Feaster  *
***************************/
#include "functions.h"

void checkArg(int check) {
    if(check != 3) {
        fprintf(stderr, "There were not enough command line arguments.\n");
        exit(0);
    }
}

int getFileCount(FILE* fp) {
    int counter = 0;
    char c = '\0';
    while(c != EOF) {
        c = fgetc(fp);
        counter++;
    }
    retFP(fp);
    return counter-1;
}

void retFP(FILE* fp) {
    if( fseek(fp, 0, SEEK_SET) != 0 ) {
        fprintf(stderr, "fseek failed!\n");
        exit(0);
    } else {
        fprintf(stderr, "%ld\n", ftell(fp));
    }
}

void readFile(char* arr, FILE* fp, int size) {
    int num = fread(arr, sizeof(char), size, fp);
    if( num != size ) {
        fprintf(stderr, "fread failed!\n");
        exit(0);
    } else {
        retFP(fp);
    }
}

void ASCII(char* arr, FILE* fp, int numElements) {
    int lineNum = 1;
    fprintf(fp, "ASCII:\n%d: ", lineNum);
    for(int i = 0; i < numElements; i++) {
        if( (i%9 == 0) && (i != 0) ) {
            lineNum++;
            fprintf(fp, "\n%d: %d ", lineNum, arr[i]);
        }
        else {
            fprintf(fp, "%d ", arr[i]);
        }
    }
    fprintf(fp, "\n");
}

void Binary(char* arr, FILE* fp, int numElements) {
    int lineNum = 1;
    fprintf(fp, "\nBinary:\n");
    for(int i = 0; i < numElements; i++) {
        fprintf(fp, "\n%d: ", lineNum);
        for (int j = 7; j >= 0; j--) {
            int k =  arr[i] >> j;
            if (k & 1) {
                fprintf(fp,"1 ");
            } else
                fprintf(fp,"0 ");
            }
            lineNum++;
        }
}

void print(void(*fp)(char*, FILE*, int), char* arr, FILE* filePtr, int num) {
    if(fp == &ASCII) {
        ASCII(arr, filePtr, num);
    } else {
        Binary(arr, filePtr, num);
    }
}

void checkFile(FILE* fp) {
    if(fp == NULL) {
        fprintf(stderr, "fopen() failed in file %s, at line #%d, of function %s\n", __FILE__, __LINE__, __FUNCTION__);
        exit(0);
    }
}
