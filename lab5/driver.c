/* driver for lab 4 - ppm image lab */

#include <stdio.h>
#include <stdlib.h>
#include "src/ppm/ppm_info.h"


int main(int argc, char* argv[]) {
	// check that 3 arguments were entered at the command-line
   if(argc != 3) {
      printf("USAGE: <executable> <oldImage> <newImage>\n\n");
      return -1;
   }

	// open file for reading in and a new output file
   FILE* oldImage = fopen(argv[1], "r");
   FILE* newImage = fopen(argv[2], "w");

   if(!oldImage || !newImage) {
      printf("ERROR: File(s) could not be opened.\n");
      return -1;
   }

	// read in the image
	// this is where the allocation is done and everything 
	// is read in from the input file; a pointer to the 
	// image is returned
   image_t* image = read_ppm(oldImage);

	// gray scale the image
	gray_scale(image);

   //write the image to the output newImage file 
   write_p6(newImage, image);

	free (image);
	free (newImage);
  	return 0;
}
