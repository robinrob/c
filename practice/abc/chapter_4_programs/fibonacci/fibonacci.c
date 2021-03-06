/* Displays the Fibonacci sequence and sequence of Fibonacci quotients. */

#include <stdio.h>

#define ITERATIONS 20

int main(void)
{
	int i, a = 0, b = 1, c = 0;
	
	printf("%-10s%s%-10s", "number:", "          ", "quotient:\n");
	for (i = 0; i < ITERATIONS; ++i)
	{
		c = a + b;
		printf("%-10d%s%-10f\n", c, "          ", (float) c / b);
		a = b;
		b = c;
	}
	
	return 0;
}
