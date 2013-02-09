/* Merges two ordered arrays into a third ordered array
 * mergeSort.c
 *
 *  Created on: Feb 5, 2010
 *      Author: user
 */

#include "mergesort.h"

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

/* Merges the two given arrays with the given sizes into a given third array */
void merge(int a[], int b[], int c[], int n, int m)
{
	register int i = 0, j = 0, k = 0;

	while (k < (n + m)) {
		if (((a[i] > b[j]) && (i < n)) || (j >= m)) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
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

/* Sorts a given array of size n */
void mergesort(int *a, int n)
{
	register int i, j, k;
	int power = 0, *w, *comps, n_comps = 1, start;
	
	w = calloc(n, sizeof(int));
	comps = get_comps(n);
	for (power = 1; power * 2 <= n; power *= 2) {
		++n_comps;
	}

	for (i = 0, start = 0; i < n_comps; ++i) {
		if (comps[i]) {
			for (j = 1; j < power; j *= 2) {
				for (k = 0; (k + j) < power; k += 2 * j) {
					merge(a + start + k, a + start + k + j, w + start + k, j, j);
				}
				for (k = start; k < start + power; ++k) {
					a[k] = w[k];
				}
			}
			merge(a, a + start, w, start, power);
			for (k = 0; k < start + power; ++k) {
				a[k] = w[k];
			}
			start += power;
		}
		power /= 2;
	}
		
	free(w);
}

/* Returns an array holding the components of the given number in base 2 */
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
