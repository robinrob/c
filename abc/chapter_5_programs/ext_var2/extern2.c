/* I don't wanna hear no blah blah blah. */

#include <stdio.h>

static int a = 1, b = 2, c = 3;

int main(void)
{
	extern int a, b, c;

	printf("%-3d%-3d%-3d\n", a, b, c); //1 2 3
	return 0;
}

