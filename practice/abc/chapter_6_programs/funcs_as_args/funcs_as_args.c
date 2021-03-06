/* Using a function as an argument to a function. */

#include <stdio.h>
#include <math.h>

#define POINTS 50

double one_over(double);
double sum_square(double f(double), double lower_limit, double upper_limit, int points);
double sum(double f(double), double lower_limit, double upper_limit, int points);
double sin(double);
double cos(double);

int main(void)
{
	printf("sum of sin^2(x) from %.5lf to %.5lf: ", 0.0, 2 * M_PI);
	printf("%lf\n", sum_square(sin, 0.0, 2 * M_PI, POINTS));
	printf("sum of sin(x) from %.5lf to %.5lf: ", 0.0, 2 * M_PI);
	printf("%lf\n\n", sum(sin, 0.0, 2 * M_PI, POINTS));

	printf("sum of cos^2(x) from %.5lf to %.5lf: ", 0.0, 2 * M_PI);
	printf("%lf\n", sum_square(cos, 0.0, 2 * M_PI, POINTS));
	printf("sum of cos(x) from %.5lf to %.5lf: ", 0.0, 2 * M_PI);
	printf("%lf\n\n", sum(cos, 0.0, 2 * M_PI, POINTS));

	printf("sum of (1 / x)^2 from %.5lf to %.5lf: ", 1.0, 1000.0);
	printf("%lf\n", sum_square(one_over, 1, 1000, 1000));
	printf("pi^2 / 6: %lf\n", M_PI * M_PI / 6);
	printf("sum of 1 / x from %.5lf to %.5lf: ", 1000.0, 1000.0);
	printf("%lf\n", sum(one_over, 1, 51, 1000));

	return 0;
}

double one_over(double x)
{
	return 1.0 / x;
}

double sum_square(double f(double x), double lower_limit, double upper_limit, int points)
{
	double x, sum = 0.0;
	for (x = lower_limit; x < upper_limit; x += (upper_limit - lower_limit) / points)
		sum += f(x) * f(x);
	return sum;
}

double sum(double f(double x), double lower_limit, double upper_limit, int points)
{
	double x, sum = 0.0;
	for (x = lower_limit; x < upper_limit; x += (upper_limit - lower_limit) / points)
		sum += f(x);
	return sum;
}
