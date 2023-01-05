/* Jacob Martin
 * CPSC 1020-1021
 * Section 004
 * This file holds important info used for the other files
 * such as the struct used for multiple variables
 * and 2 function prototypes*/

#ifndef DEFS_H
#define DEFS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct pair {
	int x;
	float y;
	struct pair *next;
} pair_t;

void createNewNode(pair_t **theList);
void printListValues(pair_t *theList);

#endif
