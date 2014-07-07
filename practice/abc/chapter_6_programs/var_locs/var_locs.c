/* Checking memory addresses of various variables to see if they are stored contiguously. */

#include <stdio.h>

int main(void)
{
	char a, b, c, *p, *q, *r;

	printf("%s%p\n%s%p\n%s%p\n%s%p\n%s%p\n%s%p\n",
			"&a: ", &a,
			"&b: ", &b,
			"&c: ", &c,
			"&p: ", &p,
			"&q: ", &q,
			"&r: ", &r);

	int d = 1, e = 2, f = 3;

	printf("\n");
	printf("%s%p\n%s%d\n%s%p\n",
			"&d = ", &d,
			"&e = ", &e,
			"&f = ", &f);

	printf("\n");
	printf("%s%ul\n%s%ul\n%s%ul\n",
			"&d = ", &d,
			"&e = ", &e,
			"&f = ", &f);

	return 0;
}
