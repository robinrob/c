/* Calculates e to an arbitrary precision using two algorithms. */

#include <stdio.h>

#define E 2.7182818284
#define TOL 0.001

int factorial(int n);

int main(void)
{
	double x0, x1;
	int n, i, cnt_1 = 0, cnt_2 = 0;

	n = 1;
	x1 = (1 + 1.0 / n);
	while (((E - x1) > TOL) || ((x1 - E) > TOL)) {
		++n;
		x1 = (1 + 1.0 / n);
		for (i = 1; i < n; ++i)
			x1 *= (1 + 1.0 / n);
		printf("%lf\n", x1);
		++cnt_1;
	}
	printf("e using method 1: %lf\n", x1);

	x1 = 1.0;
	i = 1;
	while (((E - x1) > TOL) || ((x1 - E) > TOL)) {
		x1 += 1.0 / factorial(i);
		printf("%lf\n", x1);
		++i;
		++cnt_2;
	}
	printf("e using method 2: %lf\n", x1);
	printf("Iterations for method 1: %d\n", cnt_1);
	printf("Iterations for method 2: %d\n", cnt_2);

	return 0;
}

int factorial(int n)
{
	int m = n - 1;
	while (m > 1) {
		n = n * m--;
	}
	return n;
}

