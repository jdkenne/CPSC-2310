#include "src/functions.h"


int main(int argc, char* argv[])
{
    FILE* input = fopen("input.ppm", "r");
    FILE* output = fopen("output.ppm", "w");

    header_t hdr;
    readHeader(&hdr, input);
    pixel_t* pix = (pixel_t*) malloc (hdr.width*hdr.height*sizeof(pixel_t));;
    readPixls(pix, input, hdr);
    color2Negative(hdr, pix);
    writeImage(pix, hdr, output);

   free(pix);
   return 0;

}
