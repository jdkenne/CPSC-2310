#include "functions.h"
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
#define ABS(a) (a>=0?a:-1*a)
#define LARGEST(a,b,c) (a<b?MAX(b,c):MAX(a,c))
#define SMALLEST(a,b,c) (a<b?MIN(a,c):MIN(b,c))
#define DEBUG_FPRINT() (fprintf(stderr, "In file %s Line %d\n", __FILE__, __LINE__))
#define ISEVEN_ODD(a) (a%2==0?"EVEN": "ODD")
#define MALLOC(a,b) ((b*)malloc(a))

int main(void) {
    printf("Sent in %d and %d with action %d returned %d\n", 1, 2, 2, printReturn(1,2,2));
    printf("Sent in %d and %d with action %d returned %d\n", 2, 2, 1, printReturn(2,2,1));
    printf("Sent in %d and %d with action %d returned %d\n", 3, 4, 3, printReturn(3,4,3));
    printf("Sent in %d and %d with action %d returned %d\n", 4, 1, 9, printReturn(4,1,9));

    //Macro Usage
    printf("\n\n MACRO CALLS \n\n");
    printf("Sent in %d and %d MAX: %d\n", 5, 4, MAX(5,4));
    printf("Sent in %.2f and %.2f MAX: %.2f\n", 10.9, 11.2, MAX(10.5,11.9));
    printf("Sent in %c and %c MAX: %c\n", 'a', 'b', MAX('a','b'));

    printf("\n");

    printf("Sent in %d and %d MIN: %d\n", 5, 4, MIN(5,4));
    printf("Sent in %.2f and %.2f MIN: %.2f\n", 10.9, 11.2, MIN(10.5,11.9));
    printf("Sent in %c and %c MIN: %c\n", 'a', 'b', MIN('a','b'));

    printf("\n");

    printf("Sent in %d ABS: %d\n", 4, ABS(4));
    printf("Sent in %d ABS: %d\n", -4, ABS(-4));
    printf("Sent in %d ABS: %d\n", 4, ABS(0));

    printf("\n");


    printf("Sent in %d %d %d Largest: %d\n", 4, 1, 9, LARGEST(4, 1, 9));
    printf("Sent in %c %c %c Largest: %c\n", 'a', 'b', 'c', LARGEST('a', 'b', 'c'));
    printf("Sent in %c %c %c Largest: %c\n", 'c', 'b', 'a', LARGEST('c', 'b', 'a'));

    printf("\n");

    printf("Sent in %d %d %d Smallest: %d\n", 4, 1, 9, SMALLEST(4, 1, 9));
    printf("Sent in %c %c %c Smallest: %c\n", 'a', 'b', 'c', SMALLEST('a', 'b', 'c'));
    printf("Sent in %c %c %c Smallest: %c\n", 'c', 'b', 'a', SMALLEST('c', 'b', 'a'));

    printf("\n");

    DEBUG_FPRINT();
    printf("%d which is %s\n", 4, ISEVEN_ODD(4));
    printf("%d which is %s\n", 9, ISEVEN_ODD(9));

    printf("\n");

    //Malloc Macro usage
    int *Freddy = NULL;
    Freddy = MALLOC(5, int);
    if (Freddy != NULL){
        printf("The address of Freddy is: %p\n\n", Freddy);
    } else {
        printf("NULL\n");
    }
    
    return 0;
}