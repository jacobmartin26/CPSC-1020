//mainDriver
//Jacob Martin
//CPSC 1020-21
//10/27/21
//
//This file calls the needed functions
//and outputs the data.

#include "lab9.h"

int main() {
        // Define the vector that will hold the names and birthdays
        vector<Person> friends;

        // Call a function to read the data from a file into the array
        getData(friends);

        // Call a function to sort the data in date order
        selectionSort(friends);

        // Call a function to display the (now sorted) data
        cout << endl << endl;
        cout << "Birthday List \n" << "Date    Name \n" << "============= \n";
        displayBirthdays(friends);

	friends.clear();

        return 0;
}

