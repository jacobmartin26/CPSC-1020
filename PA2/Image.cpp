//Jacob Martin
//
//File that uses image class

#include "Image.h"

//Constructs image by calling getHead and getPix
//Inputs: File input
Image::Image(ifstream& imgFile)
{
header = getHead(imgFile);
pixel = getPix(imgFile, header);
}
Image::Image(const Image& fileObject)
{
header = fileObject.header;
pixel = fileObject.pixel;
}
Image::~Image()
{
}

//Vector to hold pixel data and read pixel data
//Inputs:Input file & header
//Outputs: pixel vector
vector<vector<Pixel>> Image::getPix(ifstream& imgFile, Header& imgHead)
{
int rows;
int cols;
vector<vector<Pixel>> pixs (imgHead.hei(), vector<Pixel>(imgHead.wid()));
char noWhite;
imgFile.read(&noWhite, 1);

for(rows = 0; rows < imgHead.hei(); rows++) 
{
	for(cols = 0; cols < imgHead.wid(); cols++) 
	{
		char r;
		char g;
		char b;
		imgFile.read(&r, 1);
		imgFile.read(&g, 1);
		imgFile.read(&b, 1);
		pixs[rows][cols] = Pixel((unsigned char)r, (unsigned char)g, (unsigned char)b);
	}
}
return pixs;
}

Header Image::getHead(ifstream& imgFile)
{
	Header tempHead(imgFile);
	return tempHead;
}
Image& Image::operator=(const Image& fileObject)
{
	if (this != &fileObject)
	{
		header = fileObject.header;
		pixel = fileObject.pixel;
	}
return *this;
}
Pixel& Image::operator()(int xCoord, int yCoord)
{
	return pixel.at(xCoord).at(yCoord);
}
void Image::makeHead(ofstream& fileOut)
{
	fileOut << header;
}
void Image::makePic(ofstream& fileOut)
{
	int rows;
	int cols;
	makeHead(fileOut);
		for(rows = 0; rows < header.hei(); rows++)
		{
			for(cols = 0; cols < header.wid(); cols++)
			{
				fileOut << this->pixel[rows][cols];
			}
		}
}
Header Image::head()
{
	return header;
}
vector<vector<Pixel>> Image::pixs()
{
	return pixel;
}
