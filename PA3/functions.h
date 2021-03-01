/**************************
* Josh Kennerly           *
* CPSC 2310 Fall 2020     *
* Lab Section: 002        *
* Instructor: Dr. Feaster *
**************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#define ACC = 255;

//This function takes in the integer number and converts it to binary
char* binaryConvert(unsigned int a);

//This functions prints out what actually happens based off required format
void print(unsigned int multiplicand, unsigned int multiplier, int carry, unsigned int accumulator, char* Accumulator);

//This function checks the final output with the output presented
void finCheck(unsigned int a, unsigned int b);

//This function performs the necessary operation to change values
unsigned int operation(unsigned int multiplicand, unsigned int multiplier, int* carry, unsigned int accumulator);

//This function checks to see if the input is between the appropriate range
bool preCheck(unsigned int num);

//This prints out the initial values
void initPrint(unsigned int mulitplicand, unsigned int multiplier, int carry, int accumulator);

//This checks if the lsb is 0 or 1, and changes it accordingly
int checkLSB(unsigned int multiplier);

//prints out the binary number
void binaryPrint(char* binNum);

//This creates a new binary array with the shifted value needed
unsigned int shiftBinNum(int carry, unsigned int multiplier);
