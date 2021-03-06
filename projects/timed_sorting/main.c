/* A program to time sorting of arrays using bubblesort, qsort, mergesort and quicksort. */

#include "sort.h"

#define MAX_PRINT_LENGTH 10
//#define N 100000
#define N_ARR 1
#define RANGE 10

void time_sort(int **a, int n, int n_arr, void do_sort_func(int *a, int n));
void do_bubblesort(int *a, int n);
void do_qsort(int *a, int n);
void do_mergesort(int *a, int n);
void do_quicksort(int *a, int n);


int main(void)
{
	int *a[N_ARR], *b[N_ARR], *c[N_ARR], n_el;
	register int i, j;

	srand(time(NULL));
	
	printf("Enter n: ");
	scanf("%d", &n_el);
	
	printf("\nSorting %d arrays with %d elements...\n", N_ARR, n_el);
	
	//Allocate memory for arrays.
	for (i = 0; i < N_ARR; ++i) {
	    //a[i] = calloc(n_el, sizeof(int));
	    b[i] = calloc(n_el, sizeof(int));
	    c[i] = calloc(n_el, sizeof(int));
	}
	
	//Initialise all the arrays.
	srand(time(NULL));
	for (i = 0; i < N_ARR; ++i) {
	    for (j = 0; j < n_el; ++j) {
		*(b[i] + j) = rand() % RANGE;
		*(c[i] + j) = rand() % RANGE;
	    }
	}
	
	//time_sort(b, n_el, N_ARR, do_bubblesort);
	//time_sort(c, n_el, N_ARR, do_qsort);
	time_sort(b, n_el, N_ARR, do_mergesort);
	time_sort(c, n_el, N_ARR, do_quicksort);
	
	printf("\n");
	
	//Free the memory used by the arrays.
	for (i = 0; i < N_ARR; ++i) {
	    //free(a[i]);
	    free(b[i]);
	    free(c[i]);
	}
	
	return 0;
}

//Times the sorting of the given arrays using the given sort function
void time_sort(int **a, int n, int n_arr, void do_sort_func(int *a, int n))
{
    	int i;
	start_time();
	for (i = 0; i < n_arr; ++i) {
	    do_sort_func(a[i], n);
	}
	print_time();
}

//Sort the array using bubblesort.
void do_bubblesort(int *a, int n)
{
    printf("\nBubblesort:\n");
    bubblesort(a, n);
}

//Sort the array using qsort.
void do_qsort(int *a, int n)
{
    printf("\nQsort:\n");
    qsort(a, n, sizeof(int), cmp);
}

//Sort the array using mergesort.
void do_mergesort(int *a, int n)
{
    printf("\nMergesort:\n");
    mergesort(a, n);
}

//Sort the array using quicksort.
void do_quicksort(int *a, int n)
{
    printf("\nQuicksort:\n");
    quicksort(a, a + n - 1, 3);
}
