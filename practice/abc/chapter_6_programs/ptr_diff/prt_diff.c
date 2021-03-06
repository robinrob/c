/* Testing use of type ptrdiff_t defined in stddef.h (which is defined in there to
 * be of type long int). */

#include <stdio.h>
#include <stddef.h>

int main(void)
{
	int a, b, c, *p = &a, *q = &b, *r = &c;
	ptrdiff_t diff = p - r;
	printf("diff = %ld\n", diff);
	diff = p - (ptrdiff_t *)0;
	printf("diff = %d\n", diff);
	printf("a: %d\n*p: %d\n", a, *p);
	printf("b: %d\n*p: %d\n", b, *q);
	return 0;
}
