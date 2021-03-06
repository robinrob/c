/* Sorts an array by using pointer operations. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubble_sort(int *, int);
void swap(int *, int *);
void printArray(int *, int);

int main(void)
{
	int *a, n;
	register int i;

	printf("Enter n: ");
	scanf("%d", &n);
	a = calloc(n, sizeof(int));

	srand(time(NULL));

	for (i = 0; i < n; ++i) {
		*(a + i) = (int) (rand() % 10);
	}
	
	bubble_sort(a, n);

	return 0;
}

void bubble_sort(int *a, int n)
{
	register int i, j;
	int cunt = 0, swapped;

	for (i = 0; i < n - 1; ++i) {
		swapped = 0;
		for (j = n - 1; j > i; --j) {
			printArray(a, n);
			if (*(a + j) > *(a + j - 1)) {
				swap(&(*(a + j - 1)), &(*(a + j)));
				swapped = 1;
			}
			++cunt;
		}
		if (!swapped) {
			break;
		}
	}
	
	printArray(a, n);
	printf("Number of iterations: %d\n", cunt);
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int *a, int n)
{
	register int i;

	printf("Array:\n");
	for (i = 0; i < n; ++i)
		printf("a[%d]: %d\n", i, *(a + i));
	printf("\n");
}
