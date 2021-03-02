#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int height, width;
}header_t;

typedef struct
{
    unsigned char r, g, b;
}pixel_t;

void readHeader(header_t*, FILE*);
void readPixls(pixel_t*, FILE*, header_t);
void writeImage(pixel_t*, header_t, FILE*);
void color2Negative(header_t, pixel_t*);
