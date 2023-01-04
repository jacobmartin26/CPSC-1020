// Lab 10
// Pixel.cpp
//
// Jacob Martin
// CPSC 1020-21

#include "Pixel.h"
using namespace std;

Pixel::Pixel()
{
	red = green = blue = 0;
} // default construct.

Pixel::Pixel(unsigned char r, 
	     unsigned char g, 
	     unsigned char b)
{
	red = r;
	green = g;
	blue = b;
} // param. construct.

Pixel::Pixel(const Pixel &pix)
{
	red = pix.red;
	green = pix.green;
	blue = pix.blue;
} // copy construct.


Pixel::~Pixel()
{
	return;
} // destruct.


unsigned char Pixel::r() const
{
	return red;
}
unsigned char Pixel::g() const
{
	return green;
}
unsigned char Pixel::b() const
{
	return blue;
} // getters


unsigned char& Pixel::r()
{
	return red;
}
unsigned char& Pixel::g()
{
	return green;
}
unsigned char& Pixel::b()
{
	return blue;
}// ref. getters


Pixel& Pixel::operator=(const Pixel& pix)
{
	red = pix.red;
	green = pix.green;
	blue = pix.blue;
	return *this;
} // over. op. =
ostream& operator<<(ostream& out, const Pixel& pix)
{
	out << pix.red << pix.green << pix.blue;
	return out;
} // friend over. op. <<
