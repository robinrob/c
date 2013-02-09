/* Testing the time function. */

#include <stdio.h>
#include <time.h>

int main(void)
{
	clock_t t1, t2;
	float ratio;
	
	ratio = 1./CLOCKS_PER_SEC;
	
	printf("The time is: %.1lf\n", (float) time(NULL));
	printf("Clocks per sec: %.1lf\n", CLOCKS_PER_SEC);
	printf("Time 1: %.1f\n", t1 = clock());
	printf("Time 2: %.1f\n", t2 = clock());
	printf("Time difference (s): %f\n", ratio * (long) t2 - ratio * (long) t1);
	
	return 0;
}
