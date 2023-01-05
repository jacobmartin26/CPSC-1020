/* Jacob Martin
 * CPSC 1020-1021
 * Section 004
 * This file contains main() and is used by the user to 
 * make a new list using createNewNode()
 * and/or to print the values in the list using printListValues()*/

#include "defs.h"

int main(void) {

	struct pair *pairList = NULL;//pointer to beginning and passed to other functions
	int userChoice;// Sees if user wants to enter more values in list

	do {
		printf("Create new pair list? 1 for yes, anything else for no\n");// gets value from user
		printf("Your choice: ");
		scanf("%d", &userChoice);
		printf("\n");

		if(userChoice == 1){// executes function if user wishes to create new list pair
			createNewNode(&pairList);
		}
	} while (userChoice == 1);// loops as long as user wants to make new list

	printListValues(pairList);// executes function to print values

	return 0;
}

