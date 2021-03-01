/**************************
* Josh Kennerly           *
* CPSC 2310 Fall 2020     *
* Lab Section: 002        *
* Instructor: Dr. Feaster *
**************************/
#include "functions.h"

int main (void) {
    unsigned int firstNum = -257;
    unsigned int secNum = -257;
    int carry = 0;
    unsigned int accumulator = 0;
    char* Accumulator = binaryConvert(accumulator);
    printf("Please enter a value for the first number\n");
    scanf("%u", &firstNum);
    while(preCheck(firstNum) != true) {
      printf("This value is invalid! Please try again!\n");
      scanf("%u", &firstNum);
    }
    printf("Please enter a value for the second number\n");
    scanf("%u", &secNum);
    while(preCheck(secNum) != true) {
      printf("This value is invalid! Please try again!\n");
      scanf("%u", &secNum);
    }
    initPrint(firstNum, secNum, carry, accumulator);
    printf("Step 1:    ");
    print(firstNum, secNum, carry, accumulator, Accumulator);
    accumulator = shiftBinNum(carry, firstNum);
    Accumulator = binaryConvert(accumulator);
    binaryPrint(Accumulator);
    printf("                  Shift >> 1\n\n");
    printf("Step 2:    ");
    print(firstNum, secNum, carry, accumulator, Accumulator);
    accumulator = shiftBinNum(carry, firstNum);
    Accumulator = binaryConvert(accumulator);
    binaryPrint(Accumulator);
    printf("                  Shift >> 1\n\n");
    printf("Step 3:    ");
    print(firstNum, secNum, carry, accumulator, Accumulator);
    accumulator = shiftBinNum(carry, firstNum);
    Accumulator = binaryConvert(accumulator);
    binaryPrint(Accumulator);
    printf("                  Shift >> 1\n\n");
    printf("Step 4:    ");
    print(firstNum, secNum, carry, accumulator, Accumulator);
    accumulator = shiftBinNum(carry, firstNum);
    Accumulator = binaryConvert(accumulator);
    binaryPrint(Accumulator);
    printf("                  Shift >> 1\n\n");
    printf("Step 5:    ");
    print(firstNum, secNum, carry, accumulator, Accumulator);
    accumulator = shiftBinNum(carry, firstNum);
    Accumulator = binaryConvert(accumulator);
    binaryPrint(Accumulator);
    printf("                  Shift >> 1\n\n");
    printf("Step 6:    ");
    print(firstNum, secNum, carry, accumulator, Accumulator);
    accumulator = shiftBinNum(carry, firstNum);
    Accumulator = binaryConvert(accumulator);
    binaryPrint(Accumulator);
    printf("                  Shift >> 1\n\n");
    printf("Step 7:    ");
    print(firstNum, secNum, carry, accumulator, Accumulator);
    accumulator = shiftBinNum(carry, firstNum);
    Accumulator = binaryConvert(accumulator);
    binaryPrint(Accumulator);
    printf("                  Shift >> 1\n\n");
    printf("Step 8:    ");
    print(firstNum, secNum, carry, accumulator, Accumulator);
    accumulator = shiftBinNum(carry, firstNum);
    Accumulator = binaryConvert(accumulator);
    binaryPrint(Accumulator);
    printf("                  Shift >> 1\n\n");
  
    finCheck(firstNum, secNum);
    return 0;
}
