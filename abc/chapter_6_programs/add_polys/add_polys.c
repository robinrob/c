/* This program adds two polynomials. */

#include <stdio.h>
#include <time.h>

#define N 5
#define DIVISOR 1e8

void add(double f[], double g[], double h[], int n);
void print_array(double f[], int n);

int main(void)
{
	double f[N + 1], g[N + 1], h[N + 1];
	int i;
	
	srand(time(NULL));
	
	for (i = 0; i <= N; ++i) {
		*(f + i) = rand() / DIVISOR;
		g[i] = rand() / DIVISOR;
	}
	
	printf("Coefficients of f: ");
	print_array(f, N);
	printf("\n");
	printf("Coefficients of g: ");
	print_array(g, N);
	printf("\n");
	
	add(f, g, h, N);
	
	printf("Coefficients of h: ");
	print_array(h, N);
	printf("\n");
}

void add(double f[], double g[], double h[], int n)
{
	int i;
	for (i = 0; i <= n; ++i) {
		h[i] = f[i] + g[i];
	}
}

void print_array(double f[], int n)
{
	int i;
	for (i = 0; i <= N; ++i) {
		printf("%.0lf ", f[i]);
	}
}
