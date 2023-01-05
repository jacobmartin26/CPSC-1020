// Jacob Martin
//
// Driver for manipulations

#include <iostream>
#include <iomanip>
#include "Header.h"
#include "manip.h"
#include "Image.h"
#include "Pixel.h"

using namespace std;

int printMenu();
int whichImage(string, string);

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cerr << "USAGE: <executable> <inputFileName1> <inputFileName2>" << endl << endl;
		return -1;
	}
	ifstream f1(argv[1]);
	ifstream f2(argv[2]);

	if(!f1 || !f2)
	{
		cerr << "ERROR: File(s) could not be opened :(" << endl;
		return -1;
	}
Image img1(f1);
Image img2(f2);
int manipChoice = 1;
int imgChoice;
int numImg = 1;

while (manipChoice != 0)
{
	manipChoice = printMenu();

	if (manipChoice != 1 && manipChoice != 2 && manipChoice != 3)
	{
		continue;
	}

	string count = to_string(numImg);
	string imgOut = "out_"+count+".ppm";
	ofstream fileOut(imgOut);

	if (manipChoice == 1)
	{
		imgChoice = whichImage(argv[1], argv[2]);
		Image tempImg = imgChoice == 1 ? img1 : img2;
		grayScale(tempImg);
		tempImg.makePic(fileOut);
		cout << "Executed" << endl;
	}

	if (manipChoice == 2)
	{
		imgChoice = whichImage(argv[1], argv[2]);
		Image tempImg = imgChoice == 1 ? img1 : img2;
		mirror(tempImg);
		tempImg.makePic(fileOut);
	}
	
	if (manipChoice == 3)
	{
		Image tempImg(img2);
		greenScreen(tempImg, img1);
		tempImg.makePic(fileOut);
	}
	fileOut.close();
	numImg++;
}
return 0;
}

// Prints the main menu used for manipulation choice
// Inputs: none
// Outputs: Choice made by the user
int printMenu()
{
	int userChoice = 0;
	
	cout << endl << "PA2 Image Manipulation" << endl;
	cout << "0. exit program" << endl << "1. gray scale" << endl;
	cout << "2. mirror" << endl << "3. green screen" << endl;
	cin >> userChoice;

	return userChoice;
}

// Prints the two image options the user can choose from for a manipulation
// Inputs: Image Names
// Outputs: Image Choice
int whichImage(string img1, string img2)
{
	int imgChoice = 0;
	while (imgChoice !=1 && imgChoice != 2)
	{
		cout << endl << "PA2 Image Manipulation" << endl;
		cout << "Pick your image :)" << endl;
		cout << "1. " << img1 << endl;
		cout << "2. " << img2 << endl;
		cin >> imgChoice;
	}
return imgChoice;
}
