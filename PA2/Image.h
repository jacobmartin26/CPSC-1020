// Jacob Martin
//
// Header containing the Image class

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Pixel.h"
#include "Header.h"

#ifndef IMAGE_H
#define IMAGE_H

using namespace std;

class Image
{
	private:
		Header header;
		vector<vector<Pixel>> pixel;
	public:
		Image(ifstream&);
		Image(const Image&);
		~Image();
		vector<vector<Pixel>> getPix(ifstream&, Header&);
		Pixel& operator()(int, int);
		Image& operator=(const Image&);
		void makeHead(ofstream&);
		Header getHead(ifstream&);
		void makePic(ofstream&);
		Header head();
		vector<vector<Pixel>> pixs();
};

#endif
