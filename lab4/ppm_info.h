/* header file for lab 4
   no code needs to be completed in this file
*/

#ifndef PPM_INFO
#define PPM_INFO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structure that will contain the header information
// the image_t structure contains a header_t object in it
typedef struct header {
   char magicNum[3];  // will contain p6 for our programs
   int width, height, maxVal;
} header_t;


// represents an RGB pixel with integer values between 0-255
// the image_t structure contains a double pointer of this type
//		so, a pixel pointer that points to other pixel pointers
typedef struct pixel {
   unsigned char r, g, b;
} pixel_t;


// PPM Image representation
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
