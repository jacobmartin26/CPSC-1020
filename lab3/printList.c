/* Jacob Martin
 * CPSC 1020-1021
 * Section 004
 * This file contains printListValues() which prints
 * the values of the list or says the list is empty
 * if there is nothing in the list to print*/

#include "defs.h"

//function will print all the pair values in the list
//inputs: a pointer to the frint of the list
//outputs: none
void printListValues(pair_t *theList){
	if(theList == NULL) {//empty list
		printf("The list is empty.\n");
	}
	else {
		struct pair *current;
		current = theList;// new temp variable made and points to theList

		while(current != NULL) {//traverses through list
			printf("Value of x: %d, value of y: %.2lf\n", current->x, current->y);//prints values
			current = current->next;
		}
	}
}
