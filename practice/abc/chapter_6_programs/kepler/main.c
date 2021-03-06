/* Main file. */

#include "kepler.h"

int cnt = 0;
const dbl eps = 1e-15;
const dbl e = 0.5;
const dbl m = 2.2;

int main(void)
{
	dbl a = -100.0;
	dbl b = +100.0;
	dbl root;

	assert(kepler(a) * kepler(b) <= 0.0);
	root = bisection(kepler, a, b);
	printf("%s%d\n%s% .15f\n%s% .15f\n",
			"No. of fct calls: ", cnt,
			"approximate root: ", root,
			"  Function value: ", kepler(root));
	return 0;
}
