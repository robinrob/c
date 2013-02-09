/* Simulating call by reference by using pointers. */

#include <stdio.h>

void swap(int *, int *);

int main(void)
{
	int a = 1, b = 2;

	printf("a: %d\nb: %d\n", a, b);
	swap(&a, &b);
	printf("a: %d\nb: %d\n", a, b);

	return 0;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
