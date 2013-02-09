/**
* This program multiplies two polynomials together.
**/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 2

void print_array(int f[], int n);
void add(int f[], int g[], int h[], int n);
void multiply(int f[], int g[], int h[], int n);

int main(void)
{
	int f[N + 1], g[N + 1], h[N * N + 1];
	int i;
	
	//This method of allocation to h (as a pointer) could be used if operation to be 	//done(add/multiply) on f and g is not known beforehand:
	//h = calloc(N * N + 1, sizeof(int));
	
	srand(time(NULL));
	
	for (i = 0; i <= N; ++i) {
		f[i] = (int) (rand()) % 6;
		g[i] = (int) (rand()) % 6;
	}
	
	printf("Coefficients of f: ");
	print_array(f, N);
	printf("\n");
	printf("Coefficients of g: ");
	print_array(g, N);
	printf("\n");
	
	multiply(f, g, h, N);
	
	printf("Coefficients of h: ");
	print_array(h, N * N);
	printf("\n");
}

void print_array(int f[], int n)
{
	int i;
	for (i = 0; i <= n; ++i) {
		printf("%5d ", f[i]);
	}
}

void multiply(int f[], int g[], int h[], int n)
{
	int i, j, m;
	for (m = 0; m <= (n * n); ++m) {
		h[m] = 0;
		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= n; ++j) {
				if (i + j == m) {
					h[m] += f[i] * g[j];
				}
			}
		}
	}
}
