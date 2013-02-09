/* Messing about with pointers. This shows an interesting use of
 * pointer operations...! */

#include <stdio.h>

int main(void)
{
	int i = 6, *p, j = 2;
	p = &i;

	printf("Value of i: %d\n"
			"Value of &i or p: %p\n", *p, p);
	printf("Value at the address pointed to by p: %d\n", *p);

	*p = j;

	printf("\nValue of i: %d\n"
			"Value of &i or p: %p\n", *p, p);
	printf("Value at the address pointed to by p: %d\n", *p);

	return 0;
}
