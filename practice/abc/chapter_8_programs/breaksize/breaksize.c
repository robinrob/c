/* Program to find the average pivot value and break size returned by
 * find_pivot and partition functions.
 */

#include "breaksize.h"

int main(void)
{
    int a[N_EL], i, j, k, pivot, *p, brk;
    float avg_piv = 0.0, avg_brk = 0.0;
    srand(time(NULL));
    
    //Computing results
    for (i = 3; i <= 7; i += 2) {
	for (j = 1; j <= N_TEST; ++j) {
	    for (k = 0; k < N_EL; ++k) {
		a[k] = rand() % RANGE;
	    }
	    find_pivot(a, a + N_EL - 1, &pivot, k);
	    p = partition(a, a + N_EL - 1, pivot);
	    avg_piv = (avg_piv * (j - 1) + pivot) / j;
	    brk = p - a;
	    avg_brk = (avg_brk * (j - 1.0) + brk) / j;
	}
	
	//Display results
	printf("\n%s%d%s\n%s%f\n%s%f\n\n",
	   "results for find_pivot_", i, ":",
	   "average pivot: ", avg_piv,
	   "average break size: ", avg_brk);
    }
    
    return 0;
}
