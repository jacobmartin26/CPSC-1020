#include <iostream>
#include <fstream>
#include "Image.h"

#ifndef MANIP_H
#define MANIP_H

void grayScale(Image& img);

void mirror(Image& img);

void greenScreen(Image& imgOne, Image& imgTwo);

#endif
