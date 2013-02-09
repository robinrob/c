/* Functions for the sortAlphabetically project
 * functions.c
 *
 *  Created on: Feb 10, 2010
 *      Author: user
 */

#include "sort_words.h"

void error_exit_calloc_failed(void) {
	printf("ERROR: calloc failed\n");
	exit(0);
}

void error_exit_too_many_words(void) {
	printf("ERROR: too many words for array (max %d)\n", N);
	exit(0);
}

void error_exit_word_too_long(void) {
	printf("ERROR: word too long (max length %d)\n", MAXWORD);
	exit(0);
}

void swap(char **p, char **q) {
	char *temp;

	temp = *q;
	*q = *p;
	*p = temp;
}

void wrt_words(char *w[N], int n) {
	register int i;
	for (i = 0; i < n; ++i) {
		printf("%s\n", w[i]);
	}
}

void sort_words(char *w[N], int n) {
	register int i, j, k;

	for (i = 0; i < n; ++i) {
		for (j = i + 1; j < n; ++j) {
			for (k = 0; k < N; ++k) {
				if (*(w[i] + k) > *(w[j] + k)) {
					swap(&w[i], &w[j]);
					break;
				}
				else if (*(w[i] + k) == *(w[j] + k)) {
					continue;
				}
				else {
					break;
				}
			}
		}
	}
}

void mergesort_words(char *a[N], int n)
{
	register int i, j, k;
	int power = 0, *comps, n_comps = 1, start;
	char *w[N];
	
	for (i = 0; i < n; ++i) {
		w[i] = calloc(strlen(a[i]), sizeof(char));
		w[i] = strcpy(w[i], a[i]);
	}
	
	comps = get_comps(n);
	for (power = 1; power * 2 <= n; power *= 2) {
		++n_comps;
	}
	
	for (i = 0, start = 0; i < n_comps; ++i) {
		if (comps[i]) {
			for (j = 1; j < power; j *= 2) {
				for (k = 0; (k + j) < power; k += 2 * j) {
					merge(a, start + k, j, a, start + k + j, j, w, start + k);
				}
				for (k = start; k < start + power; ++k) {
					a[k] = w[k];
				}
			}
			merge(a, 0, start, a, start, power, w, 0);
			for (k = 0; k < start + power; ++k) {
				a[k] = w[k];
			}
			start += power;
		}
		power /= 2;
	}
	
	wrt_words(a, n);	
	for (i = 0; i < n; ++i) {
		free(w[i]);
	}
}

/* Merges the two given arrays with the given sizes into a given third array */
void merge(char *a[N], int a0, int n, char *b[N], int b0, int m, char *c[N], int c0)
{
	register int i = 0, j = 0, k = 0;
	
	while (k < (n + m)) {
		if (((j < m) && str_comp(a[a0 + i], b[b0 + j], MAXWORD)) || (i >= n)) {
			c[c0 + k++] = b[b0 + j++];
		}
		else {
			c[c0 + k++] = a[a0 + i++];
		}
	}
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

int str_comp(char *a, char *b, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		if (a[i] > b[i]) {
			return 1;
		}
		else if (a[i] == b[i]) {
			continue;
		}
		else {
			return 0;
		}
	}
	return 0;
}
