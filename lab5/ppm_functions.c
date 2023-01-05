// ppm functions for lab 4 and the first 
// lecture programming assignment



#include "ppm_info.h"


// will create a header object, read in the header info from the file
// into the header object, and return the header object back to read_ppm()
// inputs:  file pointer to the input image
// outputs: the header object containing the header info from the input file
header_t read_header(FILE* image_file) {
	header_t theHeader;
   fscanf(image_file, "%s %d %d %d ",
      theHeader.magicNum, &theHeader.width, 
		&theHeader.height, &theHeader.maxVal);
   return theHeader;
}


// will write the header info to the output image file
// called from write_p6() function
// inputs:  file pointer to output image file & the header
// outputs:  none
void write_header(FILE* out_file, header_t header) {
   fprintf(out_file, "%s %d %d %d ",
      header.magicNum, header.width, header.height, header.maxVal);
}


// called from the main() function
// first calls read_header() to initialize header info
// then forwards the header on to  read_pixels() where
// space will be allocated for the entire image and 
// the pixel data will be read
// inputs:  the input file pointer
// outputs:  the image pointer
image_t* read_ppm(FILE* image_file) {
   header_t header = read_header(image_file);
   image_t* image = NULL;
   image = read_pixels(image_file, header);
   return image;
}


// function to allocate memory for the image
// and read in the pixel data 
// inputs:  input image file pointer and the header
//			   that was already initialized
// outputs:  the image pointer
image_t* read_pixels(FILE* image_file, header_t header) {
   int row = 0;
   int col = 0;
   unsigned char red,green,blue;
   red = green = blue = 0;
   image_t* image= allocate_memory(header);
   for(row = 0; row < header.height; row++) {
      for(col = 0; col < header.width; col++) {
         fscanf(image_file, "%c%c%c", &red, &green, &blue);
         image->pixels[row][col].r = red;
         image->pixels[row][col].g = green;
         image->pixels[row][col].b = blue;
      }
   }

   return image;
}


// will user the header info to allocate memory for the image
// inputs:  the header
// outputs:  the image pointer
image_t* allocate_memory(header_t header) {
   int row;

   /* First allocate memory for the image_t . The image_t
	   has a header and a double pointer for the pixels            */
   image_t* image = (image_t*) malloc(sizeof(image_t));

   /* After you have allocated the memory for the image_t, 
	   you can now set the header equal to the header passed in.   */
   image->header = header;

   /* Now we need to allocate the memory for the actual pixels.  
	   This is a 2d array so allocate for the 2D array.            */
   image->pixels = (pixel_t**) malloc(sizeof(pixel_t*) * header.height);
   for(row = 0; row < header.height; row++) {
      image->pixels[row] = (pixel_t*)malloc(sizeof(pixel_t) * header.width);
   }

   return image;
}


// make each color pixel the average of the r, g, b components
// which will gray-scale the image
// inputs:  the image pointer
// outputs:  none
void gray_scale(image_t* image) {
   int row = 0;
   int col = 0;
	int avg = 0;
   header_t header = image->header;
   for(row = 0; row < header.height; row++) {
      for(col = 0; col < header.width; col++) {
			avg = ( image->pixels[row][col].r +
			        image->pixels[row][col].g +
					  image->pixels[row][col].g ) / 3;
         image->pixels[row][col].r = avg;
         image->pixels[row][col].g = avg;
         image->pixels[row][col].b = avg;
      }
   }
}


// write the image to the output image file
// inputs:  output image file pointer and the pointer to the image
// outputs:  none
void write_p6(FILE* out_file, image_t* image) {
   int row = 0;
   int col = 0;
   //unsigned char red,green,blue;
   header_t header = image->header;
   write_header(out_file, header);
   //red = green = blue = 0;
   /*Loop through the image and print each pixel*/
   for(row = 0; row < header.height; row++) {
      for(col = 0; col < header.width; col++) { 
			fprintf(out_file, "%c%c%c",
         image->pixels[row][col].r,
         image->pixels[row][col].g,
         image->pixels[row][col].b);
      }
   }
}


