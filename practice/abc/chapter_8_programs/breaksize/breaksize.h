#include <stdio.h>

#define N_EL 100000
#define RANGE 1000
#define N_TEST 50

typedef enum {yes, no} yes_no;

yes_no find_pivot(int *left, int *right, int *pivot_ptr, int n_piv);
int *partition(int *left, int *right, int pivot);
