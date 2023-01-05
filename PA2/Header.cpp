#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

Header::Header()
{
	magicNum = "P6";
	width = 400;
	height = 600;
	biggestValue = 255;
}

Header::Header(ifstream& fileUsed)
{
	fileUsed >> magicNum >> width >> height >> biggestValue;
}

Header::Header(string num, int wid, int hei, int big)
{
	magicNum = num;
	width = wid;
	height = hei;
	biggestValue = big;
}

int Header::wid()
{
return width;
}

int Header::hei()
{
return height;
}

int Header::big()
{
return biggestValue;
}

istream& operator>>(istream& fileEnter, Header& fileObject)
{
fileEnter >> fileObject.magicNum >> fileObject.width >> fileObject.height >> fileObject.biggestValue;
return fileEnter;
}
ostream& operator<<(ostream& fileOut, const Header& fileObject)
{
fileOut << fileObject.magicNum << endl << fileObject.width << endl;
fileOut << fileObject.height << endl << fileObject.biggestValue << endl;
return fileOut;
}
