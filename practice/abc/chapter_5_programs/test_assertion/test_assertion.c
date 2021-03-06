/* Testing use of an assertion in an untypical application. */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 1000

int main(void)
{
	int a, b, cunt, i, j, total_cunt = 0;

	srand(time(NULL));
	for (j = 0; j < ITERATIONS; ++j) {
		cunt = 0;
		for (i = 0; i < 1000; ++i) {
			a = rand() % 3 + 1;
			b = rand() % 30 + 1;
			//printf("a: %d, b: %d\n", a, b);
			if (b - a <= 1)
				continue;
			if (b - a > 2)
				;
			else
				break;
			//printf("%3d\n", ++cunt);
			++cunt;
		}
		printf("%d\n", cunt);
		total_cunt += cunt;
	}
	printf("Average count: %d\n", total_cunt / ITERATIONS);
	return 0;
}
