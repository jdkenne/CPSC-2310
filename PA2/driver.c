/***************************
* Joshua Kennerly          *
* CPSC 2310 Fall 2020      *
* jdkenne                  *
* Instructor: Dr. Feaster  *
***************************/
#include "functions.h"

int main(int argc, char* argv[]) {
    checkArg(argc);
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2],"w");
    checkFile(input);
    checkFile(output);
    int count = getFileCount(input);
    printf("File count is: %d\n", count);
    char* arr = (char*)malloc(count);
    readFile(arr, input, count);
    void(*fp)(char*, FILE*, int) = &ASCII;
    print(fp, arr, output, count);
    fp = &Binary;
    print(fp, arr, output, count);
    fclose(input);
    fclose(output);
    free(arr);
    return 0;
}
