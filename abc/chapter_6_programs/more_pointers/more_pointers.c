/* Some more uses of pointers and expressions. */

#include <stdio.h>

int main(void)
{

	char *format = "%p %d %d %d\n";
	int i = 3;
	int *p = &i;

	printf(format, p, *p + 7, 3 * **&p + 1, 5 * (p - (p - 2)));
	//address of i, 10, 10, 10

	//extension:
	printf("%p %p\n", p, p - 2);

	return 0;
}
