/* Merges two ordered arrays into a third ordered array. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array(int *a, int n);
void wrt_array(int *a, int n);
void bubble_sort(int *a, int n);
void merge(int *a, int n, int *b, int m, int *c);
void swap(int *a, int *b);

int main(void)
{
	int *a, *b, *c, n, m;

	printf("Enter size for array a: ");
	scanf("%d", &n);
	printf("Enter size for array b: ");
	scanf("%d", &m);

	a = calloc(n, sizeof(int));
	b = calloc(m, sizeof(int));
	c = calloc(n + m, sizeof(int));

	srand(time(NULL));
	fill_array(a, n);
	fill_array(b, m);
	printf("\nArray a (unsorted):\n");
	wrt_array(a, n);
	printf("\nArray b (unsorted):\n");
	wrt_array(b, m);
	printf("\nSorting array a:\n");
	bubble_sort(a, n);
	printf("\nSorting array b:\n");
	bubble_sort(b, m);
	printf("\nCombining arrays a and b:\n");
	merge(a, n, b, m, c);
	printf("\nMerged ordered array:\n");
	wrt_array(c, n + m);

	free(a);
	free(b);
	free(c);

	return 0;
}


void fill_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		a[i] = rand() % 19 - 9;
}

void wrt_array(int *a, int n)
{
	int i;

	printf("[");
	for (i = 0; i < n; ++i)
		printf("%d%s", a[i], ((i < n - 1) ? ", " : "]\n"));
}

void bubble_sort(int *a, int n)
{
	register int i, j;
	int cunt = 0;

	for (i = 0; i < n - 1; ++i)
		for (j = n - 1; j > i; --j) {
			wrt_array(a, n);
			if (*(a + j) > *(a + j - 1))
				swap(&(*(a + j - 1)), &(*(a + j)));
			++cunt;
		}
	wrt_array(a, n);
	printf("Number of iterations: %d\n", cunt);
}

void merge(int *a, int n, int *b, int m, int *c)
{
	register int i = 0, j = 0, k = 0;

	wrt_array(c, n + m);

	while (k < (n + m)) {
		if (((a[i] > b[j]) && (i < n)) || (j >= m))
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
		wrt_array(c, n + m);
	}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
