/* Testing equivalence of some logical expressions. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NO_TESTS 333

int main(void)
{
	int a, b, c, d, i, no_matches = 0, \
	result1, result2, result3, result4;

	srand(time(NULL));

	/*printf("Enter int value for a:\n");
	scanf("%d", &a);
	printf("Enter int value for b:\n");
	scanf("%d", &b);
	printf("Enter int value for c:\n");
	scanf("%d", &c);
	printf("Enter int value for d:\n");
	scanf("%d", &d);*/

	for (i = 1; i <= NO_TESTS; ++i) {
		a = rand()/10000000;
		b = rand()/10000000;
		c = rand()/10000000;
		d = rand()/10000000;

	printf("\n");

	printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

	printf("%d or %d\n", !(a > b), a <= b);
	result1 = (!(a > b) == (a <= b));

	printf("%d or %d\n", !(a <= b && c <= d)\
			, (a > b && c <= d) || (a <= b && c > d)\
			 || (a > b && c > d));
	result2 = (!(a <= b && c <= d) == ((a > b && c <= d)\
			|| (a <= b && c > d) || (a > b && c > d)));

	printf("%d or %d\n", !(a == b + 1)\
			, (a < b) || (a > b));
	result3 = (!(a == b + 1) == (a < b) || (a > b));

	printf("%d or %d\n", !(a < 1 || b < 2 && c < 3)\
			, (a >= 1) && ((b >= 2) || (c >= 3)));
	result4 = (!(a < 1 || b < 2 && c < 3) == \
	((a >= 1) && ((b >= 2) || (c >= 3))));

	result1 == 1 && result2 == 1 && \
	result3 == 1 && result4 == 1 ? ++no_matches : 1;
	}
	printf("\n%s%d\n%s%d\n",
			"Number of tests: ", NO_TESTS,
			"Number of matches: ", no_matches);
	(NO_TESTS == no_matches) ? \
			printf("Hooray!\n") : printf("Damn!\n");


	return 0;
}
