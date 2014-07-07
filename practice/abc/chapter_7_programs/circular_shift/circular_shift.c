#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int circular_shift(int a, int n);

int main(void)
{
	int a, n;
	srand(time(NULL));
	a = rand();
	printf("a: ");
	bit_print(a);
	printf("Enter number of shifts: ");
	scanf("%d", &n);
	a = circular_shift(a, n);
	printf("a: ");
	bit_print(a);
	return 0;
}

int circular_shift(int a, int n)
{
	int i;
	int m = sizeof(int) * CHAR_BIT;
	int mask = 1 << (m - 1);
	printf("mask: ");
	bit_print(mask);
	for (i = 0; i < n; ++i) {
		if (a & mask) {
			a <<= 1;
			a += 1;
		}
		else {
			a <<= 1;
		}
	}
	return a;
}
