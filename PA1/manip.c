#include "ppm_info.h"

//makes each pixel the average of rgb values which grays image
//inputs: image pointer
//outputs: none
void gray_scale(filePtr_t* image, filePtr_t** theList, int count) 
{
   int row = 0;
   int col = 0;
   int avg = 0;
	header_t header = image->theImage->header; // initializes header
	image_t* finalOutput = allocate_memory(header); // initializes space for image copy

	// file renaming and validation:
	char fileName[30] = "g"; // for the gray scale function
	strcat(fileName, image->imageFileName);

	// see if image already exists in the list
	// if the 2nd letter is a lower case 'g', then it already exists
	if(fileName[1] != 'g') 
	{
		char buf[5];
		fileName[strlen(fileName)-4] = '\0';
		int length = snprintf(buf, 5, "%d", count);
		char* imageName = (char*)malloc(length);
		sprintf(imageName, "%s%02d.ppm", fileName, count);
	

		FILE* grayedImage = fopen(imageName, "w");
		if (!grayedImage) 
		{
			fprintf(stderr, "Uh oh, grayed image file could not be opened\n\n");
			exit(1);
		}
		
		//continue initializing header
   for(row = 0; row < header.height; row++) 
   {
	   for(col = 0; col < header.width; col++) 
	   {
		   // calculate the average of the r, g, b values for the pixel
		   avg = ( image->theImage->pixels[row][col].r +
			   image->theImage->pixels[row][col].g +
			   image->theImage->pixels[row][col].b ) / 3;
		   // assigns avg to each r, g, b value of the pixel
		   finalOutput->pixels[row][col].r = avg;
		   finalOutput->pixels[row][col].g = avg;
		   finalOutput->pixels[row][col].b = avg;
	   }
   }
   write_p6(grayedImage, finalOutput); // calls function to write completed image
   fclose(grayedImage); // closes file pointer

   filePtr_t* listPtr = *theList; // list pointer
   addToList(listPtr, grayedImage, finalOutput, imageName); // adds image to list

   printf("\nGray scaled image\n\n"); // validation
}
}

// takes left and right most pixels and swaps them, then 2nd left and right
// most pixels are swapped, etc... until both sides meet in middle
// inputs: image pointer
// outputs: none
void mirror(filePtr_t* image, filePtr_t** theList, int count)
{
   	int row = 0;
   	int col = 0;
   		header_t header = image->theImage->header; // initializes header
   		image_t* finalOutput = allocate_memory(header); // makes space for the image copy

		//file renaming and validation:
		char fileName[30] = "m";
		strcat(fileName, image->imageFileName);

		if(fileName[1] != 'm')
		{
			char buf[5];
			fileName[strlen(fileName)-4] = '\0';
			int length = snprintf(buf, 5, "%d", count);
			char* imageName = (char*)malloc(length);
			sprintf(imageName, "%s%02d.ppm", fileName, count);
			FILE* mirroredImage = fopen(imageName, "w");
			if(!mirroredImage)
			{
				fprintf(stderr, "Uh oh, mirrored image file could not be opened\n\n");
				exit(1);
			}
   	for(row = 0; row < header.height; row++) 
   	{
	   	for(col = 0; col < header.width; col++) 
	   	{
		   	finalOutput->pixels[row][col] =
			image->theImage->pixels[row][header.width - 1 - col]; // swaps left & right most pixels
		   	
			finalOutput->pixels[row][header.width - 1 - col] = 
			image->theImage->pixels[row][col];
	   	}
   	}
   	write_p6(mirroredImage, finalOutput); // writes completed image
   	fclose(mirroredImage); // closes pointer
   	
	filePtr_t* listPtr = *theList; // list pointer
   	addToList(listPtr, mirroredImage, finalOutput, imageName); // adds image to list

   	printf("\nMirrored image\n\n"); // validation
	}
}
// compares pixels of the 2 images and where ever the pixel of the 2nd image
// parameter is green, writes values for pixel from 1st image parameter
// to the new image; otherwise assigns new image pixel the values from
// 2nd image parameter
// inputs: image pointer
// outputs: none
void green_screen(filePtr_t* image1, filePtr_t* image2,
	          filePtr_t** theList, int count)
{
	int row = 0;
	int col = 0;
	header_t header = image1->theImage->header; // initializes header
	image_t* finalOutput = allocate_memory(header); // makes space for image copy

	//renaming and validation
	char fileName[30] = "gs";
	strcat(fileName, image2->imageFileName);
	if(fileName[2] != 's')
	{
		char buf[5];
		fileName[strlen(fileName)- 4] = '\0';
		int length = snprintf(buf, 5, "%d", count);
		char* imageName = (char*)malloc(length);
		sprintf(imageName, "%s%02d.ppm", fileName, count);
		FILE* greenScreenedImage = fopen(imageName, "w");
		if(!greenScreenedImage)
		{
			fprintf(stderr, "Uh oh, green screen image could not open\n\n");
			exit(1);
		}
		for(row = 0; row < header.height; row++)
		{
			for(col = 0; col < header.width; col++)
			{
				if(image1->theImage->pixels[row][col].r == 0
				   && image1->theImage->pixels[row][col].g == 255
				   && image1->theImage->pixels[row][col].b == 0) // executes if pixel is green
				{
					finalOutput->pixels[row][col].r = 
					image2->theImage->pixels[row][col].r; // copies values over green pixel

					finalOutput->pixels[row][col].g =
					image2->theImage->pixels[row][col].g;

					finalOutput->pixels[row][col].b =
					image2->theImage->pixels[row][col].b;
				}
				else // executes if pixel isnt green
				{
					finalOutput->pixels[row][col].r = // keeps paw from getting copied over
					image1->theImage->pixels[row][col].r;

					finalOutput->pixels[row][col].g =
					image1->theImage->pixels[row][col].g;

					finalOutput->pixels[row][col].b =
					image1->theImage->pixels[row][col].b;
				}
			}
		}
		write_p6(greenScreenedImage, finalOutput); // writes completed image
		fclose(greenScreenedImage); // closes pointer
		filePtr_t* listPtr = *theList; // list pointer
		addToList(listPtr, greenScreenedImage, finalOutput, imageName); // adds image to list
	}
}

// gives access to image's file pointer, image name, and actual image
// inputs: list pointer
// outputs: none
void addToList(filePtr_t* frontOfList, FILE* newImage,image_t* theNewImage, char* nameOfImage)
{
	filePtr_t* fileNode = (filePtr_t*)malloc(sizeof(filePtr_t)); // creates new node in list
	fileNode->theFile = newImage; // holds new image file in list
	fileNode->imageFileName = nameOfImage; // holds name in list
	fileNode->theImage = theNewImage; // holds new image in list
	fileNode->next = NULL; // next in list

	filePtr_t* currSpot = frontOfList;
	if(currSpot == NULL)
	{
		frontOfList = fileNode; // makes front the current spot if it is null
	}
	else
	{
		while(currSpot->next != NULL)
		{
			currSpot = currSpot->next; // traverses list to find end of list
		}
		currSpot->next = fileNode; // next becomes node
	}
}
