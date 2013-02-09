/**
 * Program for evaluating polynomials, using Horner's 'rule'.
**/

#include <stdio.h>
#include <time.h>

#define N 5
#define DIVISOR 1e8;

double eval(double p[], double x, int n);
double eval_horner(double p[], double x, int n);

int main(void)
{
	double p[N + 1], x = 1.0;
	int i;
	srand(time(NULL));
	printf("Polynomial coefficients: ");
	for (i = 0; i <= N; ++i) {
		p[i] = rand() / DIVISOR;
		printf("%.4lf ", p[i]);
	}
	printf("\n");
	printf("Value from %-13s at %lf: %lf\n", "eval()", x, eval(p, x, N));
	printf("Value from %-13s at %lf: %lf\n", "eval_horner()", x, eval_horner(p, x, N));
}

double eval(double p[], double x, int n)
{
	int i, j;
	double sum = 0.0;
	for (i = 0; i <= n; ++i) {
		double term = p[i];
		for (j = 1; j < i; ++j) {
			term *= x;
		}
		sum += term;
	}
	return sum;
}

double eval_horner(double p[], double x, int n)
{
	int i;
	double sum = p[n];
	for (i = n; i > 0; --i) {
		sum = sum * x + p[i - 1];
	}
	return sum;
}
