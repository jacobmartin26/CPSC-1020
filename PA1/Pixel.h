// Lab 10
//
// Jacob Martin
// CPSC 1020-21
//
//Pixel.h


#include <iostream>

class Pixel 
{
	private:
		unsigned char red;
		unsigned char green;
		unsigned char blue;

	public:
		Pixel(); // default
		Pixel(unsigned char red2, 
		      unsigned char green2, 
		      unsigned char blue2); // parameterized
		Pixel(const Pixel &pix); // copy
		~Pixel(); // destructor

		unsigned char r() const; // get
		unsigned char g() const;
		unsigned char b() const;
		unsigned char& r(); // ref. get
		unsigned char& g();
		unsigned char& b();

		Pixel& operator=(const Pixel& pix);
		friend std::ostream& operator<<(std::ostream& out, 
						const Pixel& pix);
};

