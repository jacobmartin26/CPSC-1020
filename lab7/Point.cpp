#include "Point.h"

using namespace std;

int triCheckPoint(Point p1, Point p2, Point p3, Point cp){
	int result;
	double x, y;
	double x1, y1;
	double x2, y2;
	double x3, y3;

	x = cp.getX();
	y = cp.getY();
	x1 = p1.getX();
	y1 = p1.getY();
	x2 = p2.getX();
	y2 = p2.getY();
	x3 = p3.getX();
	y3 = p3.getY();

	double a = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
	double b = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
	double c = 1 - a - b;

	if((0 <= a) && (a <= 1) && (0 <= b) && (b <= 1) && (0 <= c) && (c <= 1))
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	return result;
}
