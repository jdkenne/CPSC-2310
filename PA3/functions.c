/**************************
* Josh Kennerly           *
* CPSC 2310 Fall 2020     *
* Lab Section: 002        *
* Instructor: Dr. Feaster *
**************************/
#include "functions.h"

char* binaryConvert(unsigned int a) {
    char* binary = (char*)calloc(8, sizeof(int));
    unsigned int b = a;
    int remainder = 0;
    int index = 0;
    while( index != 16) {
        remainder = b % 2;
        b = b / 2;
        binary[index] = remainder;
        index++;
    }
    return binary;
}

void initPrint(unsigned int multiplicand, unsigned int multiplier, int carry, int accumulator) {
    printf("Step 0:     Initialize the data M = ");
    char* Multiplicand = binaryConvert(multiplicand);
    binaryPrint(Multiplicand);
    printf(" (%d)  C = %d  ACC = %d  Q = ", multiplicand, carry, accumulator);
    char* Multiplier = binaryConvert(multiplier);
    binaryPrint(Multiplier);
    printf(" (%d)\n", multiplier);
}

void finCheck(unsigned int a, unsigned int b) {
    printf("In decimal, the solution is: %d\n", (a * b));
    printf("In binary, the solution is: ");
    char* multiplicand = binaryConvert(a*b);
    if(sizeof(multiplicand) >8) {
        printf("00000000");
    }
    binaryPrint(multiplicand);
    printf("\n");
}

bool preCheck(unsigned int a) {
    if ( (a < 0) || (a > 255) ) {
      printf("The value: %u is not correct. Try it again!\n", a);
      return false;
    } else {
        return true;
    }
}

int checkLSB(unsigned int multiplier) {
    if(multiplier & 0x01) {
        return 1;
    } else {
        return 0;
    }
}

void binaryPrint(char* binary) {
     for(int i = sizeof(binary)-1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

unsigned int operation(unsigned int multiplicand, unsigned int multiplier, int* carry, unsigned int accumulator) {
    *carry = (accumulator + multiplicand) > 255;
    if( (checkLSB(multiplier) == 1) && (accumulator + multiplicand) > 255) {
       accumulator = (accumulator + multiplicand);
       accumulator = accumulator - 256;
    } else if (checkLSB(multiplier) == 1) {
        accumulator = accumulator + multiplicand;
    }
    return accumulator;
}

unsigned int shiftBinNum(int carry, unsigned int multiplier) {
    multiplier = multiplier >> 1;
    return multiplier;
}

void print(unsigned int multiplier, unsigned int multiplicand, int carry, unsigned int accumulator, char* Accumulator) {
    int lsb = 0;
    printf("  C           ACC           Q");
    Accumulator = binaryConvert(accumulator);
    printf("\n             %d           ", carry);
    binaryPrint(Accumulator);
    printf("     ");
    char* Multiplicand = binaryConvert(multiplicand);
    binaryPrint(Multiplicand);
    printf("\n+                        ");
    char* Multiplier = binaryConvert(multiplier);
    binaryPrint(Multiplier);
    lsb = checkLSB(multiplier);
    accumulator = operation(multiplicand, multiplier, &carry, accumulator);
    if( lsb == 0 ) {
        printf("            LSB = %d no add to the ACC\n", lsb);
    } else {
        printf("            LSB = %d add M to ACC\n", lsb);
    }
    printf("-------------------------------------------------------\n");
    printf("             %d           ", carry);   
}
