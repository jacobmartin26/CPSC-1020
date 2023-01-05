#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#ifndef LAB8_H
#define LAB8_H

using namespace std;

class Person {
        private:
                string name,
                         birthday;
        public:
                void setName(string);
                void setBirthday(string);
                string getName();
                string getBirthday();
};


const int SIZE = 10;


// Function prototypes
void getData(Person []);
void selectionSort(Person []);
void displayBirthdays(Person []);

#endif
