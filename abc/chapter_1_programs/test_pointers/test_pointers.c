/* Tests equivalence of pointer expressions and array indexing using pointers. */

#include <stdio.h>

int main(void)
{
	int a = 1, b = 2, c = 3, d = 4, e = 5, *p[5];
	int i;

	p[0] = &a;
	p[1] = &b;
	p[2] = &c;
	p[3] = &d;
	p[4] = &e;

	printf("%d\n", *(p[0]));
	printf("%d\n", *(p[1]));
	printf("%d\n", *(p[2]));
	printf("%d\n", *(p[3]));
	printf("%d\n", *(p[4]));
	printf("\n");

	return 0;
}
