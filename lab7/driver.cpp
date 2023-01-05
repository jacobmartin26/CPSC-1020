//  driver.cpp file for lab 7, Fall 21 - C++ class
//  fill in missing code according to comments below

#include <iostream>
#include <fstream>
#include "Point.h"
using namespace std;

int main(int argc, char* argv[]) {

   /* Create an output file pointer.  The name of the file name
    * will be provided on the command line.
    * Check to make sure the file opened successfully.
	 * Don't forget to use C++ now and not C code.
	*/
  
   ofstream output (argv[1]);

   if(!output)
   {
	   cout << "Error opening file." << endl;
   }


        
   /* Use the output pointer to write out the PPM header information.
    * This should be a P6 image width = 500 and height = 500  
	*/
    
   output << "P6" << endl;
   output << "500 500 255" << endl;

  
   /* Create three instances of the Point class and define the three
    * points (your choice of point value)
	*/
  
   Point p1 (1, 497);
   Point p2 (329, 133);
   Point p3 (2, 496);
    
   /* test is used to test each pixel of the image. Remember you are 
    * trying to determine if test (which is a point) is within the three points
    * of the triangle
	*/
   Point test;
   int w = 0;
   int h = 0;
   int hit = 0;

   for(h = 0; h < 500; h++) {
      for(w = 0; w < 500; w++) {
         /*Set the X and Y values to the test Point*/
      
         test.setX(w);
	 test.setY(h);
        
        
         hit = triCheckPoint(p1, p2, p3, test);

         if (hit == 1) {
            unsigned char r = 82;
            unsigned char g = 45;
            unsigned char b = 128;
          
   		   /* Write the code  to output  r, g, and b */

            output << r;
	    output << g;
	    output << b;
          
          
          
          
         }
 	 else {
            unsigned char r = 246;
            unsigned char g = 102;
            unsigned char b = 61;

    			/* Write the code  to output  r, g, and b */

            output << r;
	    output << g;
	    output << b;
          
          
          

         }
      }
   }
   /* close the file pointer  */

   output.close();
    
    
   return 0;
}
