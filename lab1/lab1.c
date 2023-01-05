#include <stdio.h>

int main() {
	int a = 2, b = 8, c = -3, result;

	result = (6 + b * a * c);
	printf("result is: %d\n", result);

	result = (a - b + c * 5);
	printf("result is: %d\n", result);

	result = ((a + b) + 3 * c);
	printf("result is: %d\n", result);

	return 0;
}
