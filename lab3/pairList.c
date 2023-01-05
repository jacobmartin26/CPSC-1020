/* Jacob Martin
 * CPSC 1020-1021
 * Section 004
 * This file uses createNewNode() to create a new node 
 * and add it to the end of the list. Space is allocated for the node
 * and is added to the end, or the beginning if the list is empty.*/

#include "defs.h"

// function creates, fills, and adds new node to end of the list
// inputs: pointer to where theList points to
// outputs: none
void createNewNode(pair_t **theList){

	pair_t *lastNode = *theList;//local pointer to point to theList location

	pair_t *newNode = (pair_t*)malloc(sizeof(pair_t));//allocates memory for the newly made node

	printf("Enter an integer: ");//user enters new integer
	scanf("%d", &newNode->x);//integer put into list
	printf("\n");

	printf("Enter a float value: ");//new float
	scanf("%f", &newNode->y);//float into list
	printf("\n");

	newNode->next = NULL;//last part of list has no value now

	if(*theList == NULL){
		*theList = newNode;//makes new node the beginning if theList is empty
	}
	else {
		while(lastNode->next != NULL){//traverse through list until last value found
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;//new node end of list
	}
}
