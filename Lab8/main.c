/***********************
* Josh Kennerly       *
* CPSC 2311 - Lab 8   *
* Lab Section 002     *
***********************/
#include "functions.h"

int main (void) {
    int a[4] = {1, 2, 3, 4};
    int b[5] = {1, 2, 3, 4, 5};
    const unsigned w1 = 0x00000076;
    const unsigned w2 = 0x87654321;
    const unsigned w3 = 0x000000C9;
    const unsigned w4 = 0xEDCBA987;
    reverse_array(a, 4);
    reverse_array(b, 5);
    print_array(a, 4);
    print_array(b, 5);
    printf("0x%.2X\n", fun1(w1));
    printf("0x%.2X\n", fun2(w1));
    printf("0x%.2X\n", fun1(w2));
    printf("0x%.2X\n", fun2(w2));
    printf("0x%.2X\n", fun1(w3));
    printf("0x%.2X\n", fun2(w3));
    printf("0x%.2X\n", fun1(w4));
    printf("0x%.2X\n", fun2(w4));

    return 0;
}