//Does the system implement signed arithmetic for int bit fields?

#include <stdio.h>

struct test {
	int a : 3, b : 4;
};

int main(void)
{
	struct test x = {0};

	for ( ; ; ) {
		printf("x.a = %2d, x.b = %2d\n", x.a++, x.b++);
	}

	return 0;
}
