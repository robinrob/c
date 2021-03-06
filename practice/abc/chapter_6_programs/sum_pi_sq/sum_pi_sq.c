/* Program to calculate pi by using the series for pi squared / 6. */

#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307

double one_over(double x);
double sum_square(double f(double), int n);

int main(void)
{
	printf("Calculation of pi squared over 6: %lf\n", sum_square(one_over, 100000));
	printf("Actual value of pi squared over 6: %lf\n", M_PI * M_PI / 6.0);
	printf("Comparison of PI to M_PI:\n");
	printf("%s%.100lf\n%s%.100lf\n", "PI  : ", PI, "M_PI: ", M_PI);
	return 0;
}

double one_over(double x)
{
	return 1.0 / x;
}

double sum_square(double f(double x), int n)
{
	int k;
	double sum = 0.0;
	for (k = 1; k <= n; ++k) {
		sum += f(k) * f(k);
	}
	return sum;
}
