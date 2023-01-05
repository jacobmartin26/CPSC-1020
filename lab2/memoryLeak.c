/* memoryLeak.c
   CpSc 1021 Fall 21, lab 2
   example to use for valgrind

	this program will reserve a block of memory
	large enough to hold 100 characters.
*/

#include <stdlib.h>

int main(void) {
	char *x = malloc(sizeof(char) * 100);
	return 0;
}


