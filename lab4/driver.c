/* driver for lab 4 - ppm image lab */

// there are 5 numbered comments where code needs to be completed
// the first one is on line #18

#include <stdio.h>
#include <stdlib.h>
#include "ppm_info.h"


int main(int argc, char* argv[]) {
	// check for correct number of arguments entered on the command-line
   if(argc != 3) {
      printf("USAGE: <executable> <oldImage> <newImage>\n\n");
      return -1;
   }

	// 1.  declare 2 file pointers
	FILE* oldImage = fopen(argv[1], "r");
	FILE* newImage = fopen(argv[2], "w"); 


	// check that the files opened successfully
   if(!oldImage || !newImage) {
      printf("ERROR: File(s) could not be opened.\n");
      return -1;  
   }


	// 2. declare a pointer to an image_t called *image
	image_t *image;

	// 3. and call read_ppm function
	image = read_ppm(oldImage);


	// 4. call gray_scale function
	gray_scale(image); 


	// 5. call write_p6 function to write the newImage to a file
	write_p6(newImage, image);



   return 0;
}
