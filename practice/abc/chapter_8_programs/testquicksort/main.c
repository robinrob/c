/* Testing quicksort. */

#include "sort.h"

#define N_ELEM 10000
#define RANGE 10000
#define N_ARR 10

void sort(int **a, int n_piv);
void sort_ordered(int **a, int n_piv);
void sort_reversed(int **a, int n_piv);
void sort_rand(int **a, int n_piv);
void check_arr(int **a);
void print_arr(int a[], long int n);
void start_time(void);
double print_time(void);

//extern int cnt;

int main(void)
{
	int *a[N_ELEM];
	int i, n_piv;

	srand(time(NULL));

	for (i = 0; i < N_ARR; ++i) {
		*(a + i) = calloc(N_ELEM, sizeof(int));
	}

	printf("Enter number of pivots: ");
	scanf("%d", &n_piv);
	getchar();

	sort_rand(a, n_piv);
	sort_ordered(a, n_piv);
	sort_reversed(a, n_piv);

	printf("\nExiting program.\n");

	/*Free all arrays*/
	for (i = 0; i < N_ARR; ++i) {
		free(a[i]);
	}

	return 0;
}

/*Sorting RANDOM arrays.*/
void sort_rand(int **a, int n_piv)
{
	int i, j;

	printf("\nInitialising RANDOM arrays ...\n");
	for (i = 0; i < N_ARR; ++i) {
		for (j = 0; j < N_ELEM; ++j) {
			a[i][j] = rand() % RANGE;
		}
	}

	check_arr(a);
	printf("Press 'enter' to sort RANDOM arrays:");
	if (getchar() != '\n') {
		exit(1);
	}
	sort(a, n_piv);
	check_arr(a);
}

/*Sorting ORDERED arrays.*/
void sort_ordered(int **a, int n_piv)
{
	int i, j;

	printf("\nInitialising ORDERED arrays ...\n");
	for (i = 0; i < N_ARR; ++i) {
		for (j = 0; j < N_ELEM; ++j) {
			a[i][j] = (long) (RANGE * j) / N_ELEM;
		}
	}

	check_arr(a);
	printf("Press 'enter' to sort ORDERED arrays:");
	if (getchar() != '\n') {
		exit(1);
	}
	sort(a, n_piv);
	check_arr(a);
}

/*Sorting REVERSE-order arrays.*/
void sort_reversed(int **a, int n_piv)
{
	int i, j;

	printf("\nInitialising REVERSED arrays ...\n");
	for (i = 0; i < N_ARR; ++i) {
		for (j = 0; j < N_ELEM; ++j) {
			a[i][j] = RANGE - 1 - (long) (RANGE * j) / N_ELEM;
		}
	}

	check_arr(a);
	printf("Press 'enter' to sort REVERSED arrays:");
	if (getchar() != '\n') {
		exit(1);
	}
	sort(a, n_piv);
	check_arr(a);
}

void sort(int **a, int n_piv)
{
	printf("n_piv: %d\n", n_piv);
	int i, cnt;
	start_time();
	printf("Quicksorting ...\n");
	for (i = 0; i < N_ARR; ++i) {
		cnt = 0;
		quicksort(a[i], a[i] + N_ELEM - 1, n_piv, &cnt);
		printf("no. quicksort calls: %d\n", cnt);
	}
	printf("\n");
	print_time();
}

void check_arr(int **a)
{
	int i;
	printf("Press 'y' to check arrays ('enter' to continue):");
	if (getchar() == 'y') {
		for (i = 0; i < N_ARR; ++i) {
			printf("Array (%c) (%d elements):\n", 'a' + i, N_ELEM);
			print_arr(*(a + i), N_ELEM);
		}
		getchar();
	}
}

void print_arr(int a[], long int n)
{
	int i;
	for (i = 0; i < 5; ++i) {
		printf("%5d ", a[i]);
	}
	printf("\n    ... \n");
	for (i = n / 2; i < (n / 2 + 5); ++i) {
		printf("%5d ", a[i]);
	}
	printf("\n    ... \n");
	for (i = n - 5; i < n; ++i) {
		printf("%5d ", a[i]);
	}
	printf("\n");
}
