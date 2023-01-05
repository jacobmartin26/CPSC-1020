//Jacob Martin
//CPSC 1020-21
//10/27/2021
//This .h file holds the libraries needed, 
//the class, and the function prototypes

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <array>
#include <vector>

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

// Function prototypes
void getData(vector<Person> &friends);
void selectionSort(vector<Person> &friends);
void displayBirthdays(vector<Person> &friends);

#endif
