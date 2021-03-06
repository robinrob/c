//Testing some code using a structure with bit fields.

#include <stdio.h>

struct test {
	unsigned a : 1, b : 2, c: 3;
};

int main(void)
{
	int i;
	struct test x;

	for (i = 0; i < 24; ++i) {
		x.a = x.b = x.c = i;
		/* Try using this line instead!:
		 * x.c = x.b = x.a = i;
		 */
		printf("x.a = %d, x.b = %d , x.c = %d\n", x.a, x.b, x.c);
	}
	return 0;
}
