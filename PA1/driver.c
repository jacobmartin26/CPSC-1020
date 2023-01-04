/* driver for lab 4 - ppm image lab */

#include <stdio.h>
#include <stdlib.h>
#include "ppm_info.h"

int main(int argc, char* argv[]) 
{
	filePtr_t* userPointer;// pointer used to pick image by the user
	userPointer = (filePtr_t*)malloc(sizeof(filePtr_t));
	int i = 1;
	// check for correct number of arguments entered on the command-line
   if(argc != 3) 
   {
      printf("USAGE: <executable> <oldImage> <newImage>\n\n");
      return -1;
   }

	// 1.  declare 2 file pointers
	FILE* firstInput = fopen(argv[1], "r"); // pointer for Clemson ppm
	FILE* secondInput = fopen(argv[2], "r"); // Disney ppm

	filePtr_t* finalImage = NULL; // pointer for final image

	// check that the files opened successfully
   if(!firstInput || !secondInput) 
   {
      printf("Could not open one or more files, sad\n");
      return -1;  
   }
   if(firstInput && secondInput) 
   {
	   printf("\nFiles opened!\n\n"); // validation for opening both files
   }
   	image_t* image1; // copy of first image
	image1 = read_ppm(firstInput);

	filePtr_t* newFilePointer = (filePtr_t*)malloc(sizeof(filePtr_t));
	newFilePointer->theFile = firstInput; // points to first image
	newFilePointer->imageFileName = argv[1]; // points to image name
	newFilePointer->theImage = image1; // points to image copy
	newFilePointer->next = NULL; // next pointer
	finalImage = newFilePointer; // final image uses newFP values and info

	image_t* image2; // copy of second image
	image2 = read_ppm(secondInput);

	filePtr_t* newFilePointer2 = (filePtr_t*)malloc(sizeof(filePtr_t));
	newFilePointer2->theFile = secondInput; // same things as image1 variable
	newFilePointer2->imageFileName = argv[2];
	newFilePointer2->theImage = image2;
	newFilePointer2->next = NULL;
	finalImage->next = newFilePointer2;


  int userChoice;
  do
   {
	userChoice = printMenu1(); // calls menu to get user choice for switch

  	if ((userChoice >= 0) && (userChoice <= 3))
   	{
		switch(userChoice) {
		case 0: printf("Exiting program\n\n");
			break;
		case 1: printf("Gray scaling image\n\n"); // grays image
			userPointer = printList(finalImage);
			gray_scale(userPointer, &finalImage, i);
			i++;
			break;
		case 2: printf("Mirroring image\n\n"); // mirrors image
			userPointer = printList(finalImage);
			mirror(userPointer, &finalImage, i);
			i++;
			break;
		case 3: printf("Green screening image\n\n"); // green screens images
			userPointer = printList(finalImage);
			green_screen(newFilePointer, userPointer, &finalImage, i);
			i++;
			break;
   		}
   	}
   	else
   	{
	   	while((userChoice < 0) || (userChoice > 3)) // used for when user makes a bad choice
	   	{
	   		fprintf(stderr, "\nAlright, funny joke. Pick an actual option.\n");
	   		userChoice = printMenu1();
	   	}
   	}
   }while(userChoice != 0); // loops until user exits program


   return 0;
}
