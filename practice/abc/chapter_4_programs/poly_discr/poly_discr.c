/* Calculating the complex square root of the
 * discriminant of a polynomial of degree two. */

#include <stdio.h>
#include "sqrt2.c"

double sqrt2(double x);

int main(void)
{
	double a, b, c, discr;

	printf("Enter value for a: ");
	scanf("%lf", &a);
	printf("Enter value for b: ");
	scanf("%lf", &b);
	printf("Enter value for c: ");
	scanf("%lf", &c);

	discr = (b * b - 4 * a * c);
	if (discr >= 0)
		printf("\nSqrt of discriminant of %lfx^2 + %lfx + %lf is: %lf\n",
				a, b, c, sqrt2(discr));
	else if (discr < 0)
		printf("\nSqrt of discriminant of %lfx^2 + %lfx + %lf is: %lfi\n",
						a, b, c, sqrt2(discr * -1));

	return 0;
}
