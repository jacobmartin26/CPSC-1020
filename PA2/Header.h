#include <iostream>
#include <string>
#include <fstream>

#ifndef HEADER_H
#define HEADER_H

using namespace std;

class Header
{
	private:
		string magicNum;
		int width;
		int height;
		int biggestValue;
	public:
		Header();
		Header(ifstream&);
		Header(string, int, int, int);
		int wid();
		int hei();
		int big();
		friend istream& operator>>(istream&, Header&);
		friend ostream& operator<<(ostream&, const Header&);
};

#endif
