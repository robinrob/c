/* Divides a number by zero to see the result at runtime. */

#include <stdio.h>

int main(void)
{
	double x, y = 0;

	x = 1 / y;
	printf("x = %f\n", x);
	return 0;
}
