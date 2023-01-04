/* Jacob Martin
 * CPSC 1020-21
 * Lab 7 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <fstream>

using namespace std;

class Point {
	private:
		double x;
		double y;
	public:
		Point()
		{
			x = 0;
			y = 0;
		}
		Point(double X, double Y)
		{
			x = X;
			y = Y;
		}
		void setX(double Xval)
		{
			x = Xval;
		}
		double getX()
		{
			return x;
		}
		void setY(double Yval)
		{
			y = Yval;
		}
		double getY()
		{
			return y;
		}
};

int triCheckPoint(Point p1, Point p2, Point p3, Point cp);

#endif
