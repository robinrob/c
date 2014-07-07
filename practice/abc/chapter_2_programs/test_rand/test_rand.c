/* Testing the rand function and timing it using the time function. Since the program
 * runs so fast the timing method doesn't really work! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCALLS 100000000
#define NCOLS 8
#define NLINES 3

int main(void)
{
	int i, val;
	long begin, diff, end;

	begin = time(NULL);
	srand(time(NULL));
	printf("\nTIMING TEST: %d calls to rand()\n\n", NCALLS);
	for (i = 1; i <= NCALLS; ++i) {
		val = rand();
		if (i <= NCOLS * NLINES) {
			printf("%d, ", val);
			if (i % NCOLS == 0)
				putchar('\n');
		}
		else if (i == NCOLS * NLINES + 1)
			printf("%s\n\n", "......");
	}
	end = time(NULL);
	diff = end - begin;
	printf("%s%1ld\n%s%1ld\n%s%1ld\n%s%.10f\n\n",
			"          end time: ", end,
			"        begin time: ", begin,
			"      elapsed time: ", diff,
			"time for each call: ", (double) diff / NCALLS);
	return 0;
}
