/* Testing use of a recursive function. */

#include <stdio.h>

#define LIMIT 10

static int n = 0;

int sum(int n);
int factorial(int n);
int power(int n, int power);

int main(void)
{
	printf("The universe is never ending!\n");
	++n;
	if (n != LIMIT)
		main();
	else {
		printf("Sum of first %d integers: %d\n", n, sum(n));
		printf("Factorial of %d: %d\n", n, factorial(n));
		printf("Factorial of %d: %d\n", -n, factorial(-n));
	}
	printf("Factorial of %d: %d\n", -(n - 1), factorial(-(n - 1)));
	return 0;
}

int sum(int n)
{
	if (n <= 1)
		return n;
	else
		return (n + sum(n - 1));
}

int factorial(int n)
{
	if (n < 0) {
		return (power(-1, n) * factorial(-n));
	}
	else if (n == 0)
		return 1;
	else
		return (n * factorial(n - 1));
}

int power(int n, int power)
{
	register int i;
	int num = n;
	for (i = 1; i < -power; ++i) {
		n *= num;
	}
	return n;
}
