/* How arrays can be used by functions by using pointer
 * operations. */

#include <stdio.h>

#define N 100

double sum(double *a, int n);

int main(void)
{
	double v[N];
	register int i;

	printf("Array:\n");
	for (i = 0; i < N; ++i) {
		*(v + i) = i;
		printf("v[%d]: %.2lf\n", i, *(v + i));
	}

	printf("Sum of array: %.2lf\n", sum(&v[5], 5));
}

double sum(double *a, int n)
{
	register int i;
	double sum = 0.0;

	for (i = 0; i < n; ++i) {
		sum += *(a + i);
		printf("sum: %.2lf\n", sum);
	}
	return sum;
}
