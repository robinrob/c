/* Calculation of running average and comparison to normal average. */

#include <stdio.h>

int main(void) {
    int i, n, sum = 0;
    float avg1, avg2;
    
    printf("enter number: ");
    
    for (i = 1; scanf("%d", &n) == 1; ++i) {
	printf("sum: %d\n", sum += n);
	printf("average1: %f\n", avg1 = 1.0 * sum / i);
	printf("average2: %f\n", avg2 = ((avg2 * (i - 1) + n) / i));
	printf("enter number: ");
    }
    return 0;
}
