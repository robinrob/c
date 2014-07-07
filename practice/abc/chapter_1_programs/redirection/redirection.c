/* Program for testing redirection of input/output. */

#include <stdio.h>

int main(void)
{
	char c;
	while (scanf("%c", &c) == 1)
		printf("%c%c", c, c);

	return 0;
}
