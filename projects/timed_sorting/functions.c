/* Useful functions for the timed_sorting project. */

#include "sort.h"

/* Fills the given array of size n with random values */
void fill_array(int *a, int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; ++i) {
		a[i] = rand() % 19 - 9; //this gives negative numbers -1 to -9 as well as numbers 1 to 9!
	}
}

/* Prints the elements of the given array of size n */
void wrt_array(int *a, int n)
{
	int i;

	printf("[");
	for (i = 0; i < n; ++i) {
		printf("%d%s", a[i], ((i < n - 1) ? ", " : "]\n"));
	}
}

/* Swaps the addresses of two integer pointers */
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/* Returns an array holding the components of the base 2 representation of the given integer */
int* get_comps(int n)
{
	int n_digits, i;
	unsigned long power;
	int *comps, digit;
	
	for (power = 1, n_digits = 1; power * 2 <= n; power *= 2, ++n_digits);
	comps = calloc(n_digits, sizeof(int));

	for (i = 0; power >= 1; power /= 2, ++i) {
		digit = n / power;
		n -= digit * power;
		*(comps + i) = digit;
	}
	
	return comps;
}

/* Acomparison function to use with qsort(). */
int cmp(const void *vp, const void *vq)
{
	const double *p = vp;
	const double *q = vq;
	double diff = *p - *q;
	return ((diff >= 0.0) ? ((diff > 0.0) ? -1 : 0) : +1);
}


