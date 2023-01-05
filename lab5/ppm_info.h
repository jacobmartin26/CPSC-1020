#ifndef PPM_INFO
#define PPM_INFO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structure definitions
// header structure, to hold all the ppm header info
typedef struct header {
   char magicNum[3];
   int width, height, maxVal;
} header_t;


// Represents an RGB pixel with integer values between 0-255
typedef struct pixel {
   unsigned char r, g, b;
} pixel_t;


// PPM Image representation
// contains the header and the pixel data
typedef struct image {
   header_t header;
   pixel_t** pixels;
} image_t;


// prototypes
header_t read_header(FILE* image_file);
void write_header(FILE* out_file, header_t header);
image_t* read_ppm(FILE* image_file);
image_t* read_pixels(FILE* image_file, header_t header);
image_t* allocate_memory(header_t header);
void gray_scale(image_t* image); 
void write_p6(FILE* out_file, image_t* image);


#endif
