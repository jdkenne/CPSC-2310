#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "functions.h"

void readHeader(header_t* hdr, FILE* input)
{
    fscanf(input, "P6\n%d %d 255\n", &hdr->width, &hdr->height);
}
void readPixls(pixel_t* pix, FILE* input, header_t hdr)
{
    
    fread(pix, sizeof(pixel_t), hdr.width*hdr.height, input);
}

void writeImage(pixel_t* pix, header_t hdr, FILE* output)
{
    fprintf(output, "P6\n%d %d 255\n", hdr.width, hdr.height);
    fwrite(pix, sizeof(pixel_t), hdr.width*hdr.height, output);
}

void color2Negative(header_t hdr, pixel_t* pix)
{

    int i = 0;
    for(i = 0; i < hdr.width*hdr.height; i++)
    {
        pix[i].r = 255 - pix[i].r;
        pix[i].g = 255 - pix[i].g;
        pix[i].b = 255 - pix[i].b;
       
    }
}

#endif
