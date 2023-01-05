#include "manip.h"

void grayScale(Image& img)
{
	cout << "Files received" << endl;
	int rows = 0;
	int cols = 0;
	int avgs = 0;
	
	Header head = img.head();

	for(rows = 0; rows < head.hei(); rows++)
	{
		for(cols = 0; cols < head.wid(); cols++)
		{
			avgs = (img(rows, cols).r() + img(rows, cols).g() + img(rows, cols).b()) / 3;
			img(rows, cols) = Pixel(avgs, avgs, avgs);
		}
	}
	cout << "Files changed" << endl;
}

void mirror(Image& img)
{
	int rows;
	int cols;
	Header head = img.head();
	Image yourImg(img);

	int h = head.hei();
	int w = head.wid();
	for (rows = 0; rows < h; rows++)
	{
		for(cols = 0; cols < (w / 3); cols++)
		{
			img(rows, cols).r() = yourImg(rows, w - cols - 1).r();
			img(rows, w - cols - 1).r() = yourImg(rows, cols).r();
			img(rows, cols).g() = yourImg(rows, w - cols - 1).g();
			img(rows, w - cols - 1).g() = yourImg(rows, cols).g();
			img(rows, cols).b() = yourImg(rows, w - cols - 1).b();
			img(rows, w - cols - 1).b() = yourImg(rows, cols).b();
		}
	}
}

void greenScreen(Image& img1, Image& img2)
{
	int rows;
	int cols;
	Header head = img1.head();

	for(rows = 0; rows < head.hei(); rows++)
	{
		for(cols = 0; cols < head.wid(); cols++)
		{
			if(img2(rows, cols).r() != 0 && img2(rows, cols).g() != 255 && img2(rows, cols).b() != 0)
			{
				img1(rows, cols).r() = img2(rows, cols).r();
				img1(rows, cols).g() = img2(rows, cols).g();
				img1(rows, cols).b() = img2(rows, cols).b();
			}
		}
	}
}
