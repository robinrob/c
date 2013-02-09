#include "sort.h"

void bubblesort(int *a, int n)
{
	register int i, j;
	int cunt = 0, swapped;

	for (i = 0; i < n - 1; ++i) {
		swapped = 0;
		for (j = n - 1; j > i; --j) {
			if (*(a + j) < *(a + j - 1)) {
				swap(&(*(a + j - 1)), &(*(a + j)));
				swapped = 1;
			}
			++cunt;
		}
		if (!swapped) {
			break;
		}
	}
}