/* Merge and mergesort functions. */

#include "sort.h"

/* Merges the two given arrays with the given sizes into a given third array */
void merge(int a[], int b[], int c[], int n, int m)
{
	register int i = 0, j = 0, k = 0;

	while (k < (n + m)) {
		if (((a[i] < b[j]) && (i < n)) || (j >= m)) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}
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
