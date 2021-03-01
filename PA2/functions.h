/***************************
* Joshua Kennerly          *
* CPSC 2310 Fall 2020      *
* jdkenne                  *
* Instructor: Dr. Feaster  *
***************************/
#include <stdio.h>
#include <stdlib.h>

/*This is a callback function. This allows us to print either the ASCII or Binary 
function.*/
void print(void (*fp)(char*, FILE*, int), char*, FILE*, int);

/*This functions takes in a character array, a file pointer, and and int.
The character array stores the values read in from the input file. Then,
we print out the integer representation of the character in the array. We
do this the number of times equivalent to the number of elements inside the array*/
void ASCII(char*, FILE*, int);

/*This reads all the characters in the files and stores them into the array.*/
void readFile(char*, FILE*, int);

/*This function sets the file pointer that was used in in getFileCount back to the beginning 
of the file so we can use it again.*/
void retFP(FILE*);

/*This gets the number of elements inside of the input file and returns that value.*/
int getFileCount(FILE*);

/*This checks to see if the file was successfully opened. If it was not, it tells you where
it failed to open, at which line as well.*/
void checkFile(FILE*);

/*This checks to see if the appropriate number of command line arguments is correct.*/
void checkArg(int);

/*This function takes in a character array, a file pointer, and and int.
The character array stores the values read in from the input file. Then,
we shift each value in the array over and compare them to the value 1. This allows
us to print out either a 1 or a 0 for each value in the bit sequence for the letter.
We do this for the size of the char array.*/
void Binary(char*, FILE*, int);