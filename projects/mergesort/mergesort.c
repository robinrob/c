#include "mergesort.h"

int main(void)
{
	int *a, *w, n, m, power;
	register int i;

	printf("Enter size for array: ");
	scanf("%d", &n);

	a = calloc(n, sizeof(int));
	w = calloc(n, sizeof(int));

	for (i = 0; i < n; ++i) {
		w[i] = a[i];
	}
	
	fill_array(a, n);
	printf("\nmain(): unsorted array:\n");
	wrt_array(a, n);
	mergesort(a, n);
	printf("\nmain(): sorted array:\n");
	wrt_array(a, n);
	
	free(a);
	free(w);

	return 0;
}
