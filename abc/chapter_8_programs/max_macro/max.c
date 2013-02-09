/* Testing a macro which is supposed to give the maximum value
 * of three variables. */
 
#define MAX(x, y, z) (a = (x < y ? y : x)) < (b = (y < z ? z : y)) ? b : a
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c;
	srand(time(NULL));
	a = rand() % 20 - 10;
	b = rand() % 20 - 10;
	c = rand() % 20 - 10;
	a = b = c = 0;
	printf("max value of %d, %d and %d: %d\n", a, b, c, MAX(a, b, c));
	return 0;
}
