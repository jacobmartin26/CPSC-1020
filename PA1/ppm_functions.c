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
	// 1.  call read_header function here:
	header_t header;
	header = read_header(image_file);
  

   image_t* image = NULL;
	// 2.  call read_pixels function here:
	image = read_pixels(image_file, header);

   return image;
}


// function to allocate memory for the image
// and read in the pixel data 
// inputs:  input image file pointer and the header
// 	    that was already initialized
// outputs:  the image pointer
image_t* read_pixels(FILE* image_file, header_t header) {
   int row = 0, col = 0;
   image_t *image;
   unsigned char red, green, blue;
   red = green = blue = 0;

	// 3.  call allocate_memory function here:
	image = allocate_memory(header);
  
  
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


// will use the header info to allocate memory for the image
// inputs:  the header
// outputs: the image pointer
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
	// 4. allocate space for the first part of image->pixels 
	//    - - > the pink box on page 3 of the lab write-up
	image->pixels = (pixel_t **) malloc(sizeof(pixel_t*) * image->header.height);
  

   // 5. now allocate space for the pixels in each row of the image
	//    - - > the yellow boxes on page 3 of the lab write-up
	//    hint:  this requires a for loop
	for(row = 0; row < image->header.height; row++){
		image->pixels[row] = (pixel_t*) malloc(sizeof(pixel_t) * image->header.width);
	}

   return image;
}

// Prints the menu so the user may determine what manipulation
// to use on the image(s)
// inputs: none
// outputs: user's manipulation choice
int printMenu1()
{
	printf("\nPA1 Image Manipulation\n");
	printf(" 0. exit program\n 1. gray scale\n 2. mirror\n 3. green screen\n");

	int userChoice;
	printf("Choose how to manipulate the image(s): ");
	scanf("%d", &userChoice); // gets choice from user
	printf("\n");

	return userChoice;
}

// print the list of created files showing the file names
// inputs: the pointer to the list
// outputs: none
filePtr_t* printList(filePtr_t* theList)
{
	int fileNumber = 1, choice = 0;
	filePtr_t* curr = theList;
	if(theList == NULL)
	{
		fprintf(stderr, "\nThe list is empty.\n");
	}
	else
	{
		fprintf(stderr, "\nYour image choices are:\n");
		while(curr != NULL)
		{
			fprintf(stderr, "%d. %s\n", fileNumber, curr->imageFileName);
			fileNumber++;
			curr = curr->next;
		}
		fprintf(stderr, "\n\n");
		fprintf(stderr, "Enter image choice or 0 to quit program: ");
		fscanf(stdin, "%d", &choice);
	}
		if(choice == 0)
			exit(1);
		// reset current back to the beginning of the list and
		// find the chosen image, returning it
		curr = theList;
		for(int i = 1; i < choice; i++)
			curr = curr->next;

		return curr;
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
   //Loop through the image and print each pixel
   for(row = 0; row < header.height; row++) {
      for(col = 0; col < header.width; col++) { 
			fprintf(out_file, "%c%c%c",
         image->pixels[row][col].r,
         image->pixels[row][col].g,
         image->pixels[row][col].b);
      }
   }
}


