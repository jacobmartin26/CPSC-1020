// lab 8
// This program reads names and birthdays in from a file, stores them in an 
// array of objects, sorts the data by birthday, and displays it. To simplify 
// the program, the Person class data has been made public. The data 
// file, birthdays.dat, in the same directory.

// The class, function implementations, and main function are all 
// contained in this one file.

#include "lab8P2.h"

using namespace std;

string Person::getName(){
return name;
}

string Person::getBirthday(){
return birthday;
}

void Person::setName(string newName) {
name = newName;
}

void Person::setBirthday(string newBirthday){
birthday = newBirthday;
}

/****************************************************************
 *                            getData                           *
 * Called by: main                                              *
 * Passed   : The array holding the data                        *
 * Purpose  : Reads the data from a file into the array elements*
 ****************************************************************/
void getData(array<Person, SIZE> &friends) {
	ifstream dataIn;
	string valOne, valTwo;

	// Open the file and test that it opened correctly
	dataIn.open("birthdays.dat");
	if (!dataIn)
		cout << "Error opening data file\n";
	else {	// Read in all the data
		for (int index = 0; index < SIZE; index++) {
			getline(dataIn, valOne);
			friends.at(index).setName(valOne);

			getline(dataIn, valTwo);
			valTwo[5] = '\0';
			friends.at(index).setBirthday(valTwo);
		}
		// Close the file
		dataIn.close();
	}
}


/*************************************************************
 *                    selectionSort                          *
 * Called by: main                                           *
 * Passed   : The data array                                 *
 * Purpose  : Sorts the elements in ascending date order     *
  ************************************************************/
void selectionSort(array<Person, SIZE> &friends) {
	int startScan,     // Array indexes to be compared
		 minIndex;

	Person temp;       // Used to swap two friend elements
	string minValue;   // Will be in the birthday field of element
	                   // with minIndex
		
	// Sort array elements
	for (startScan = 0; startScan < (SIZE - 1); startScan++) {
		minIndex = startScan;
		minValue = friends.at(startScan).getBirthday();
		for (int index = startScan + 1; index < SIZE; index++) {   
			// Compare data in the birthday fields
			if (friends.at(index).getBirthday() < friends.at(minIndex).getBirthday()) {
				minValue = friends.at(index).getBirthday();
				minIndex = index;
			}
		}
		// Move elements to their new positions
		temp = friends.at(minIndex);
		friends.at(minIndex) = friends.at(startScan);
		friends.at(startScan) = temp;
	}   
}


/*************************************************************
 *                   displayBirthdays                        *
 * Called by: main                                           *
 * Passed   : The array of person objects                    *
 * Purpose  : Prints names and bithdays in order of date.    *
 *************************************************************/
void displayBirthdays(array<Person, SIZE> &friends) 
{
	string valOne, valTwo;

	for (int pos = 0; pos < SIZE; pos++)
	{
		valTwo = friends.at(pos).getBirthday();
		valOne = friends.at(pos).getName();

		cout << valTwo << "	" << valOne << endl;
	}
		cout << endl << endl;
}


/* CORRECT RESULTS

Birthday List
Date    Name
=============
02/09   Mario Rubio
03/16   Sandra Day
06/08   Sean O'Connor
07/15   Turd Ferguson
08/22   Darius Williams
09/18   Anne Dawson
10/31   Earl Turlet
11/03   Evelyn Maroto
11/22   Bill Johnson
12/01   Joaquin Baloney

*/
