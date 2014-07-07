/* Testing a for loop with putchars in it. */

#include <stdio.h>

int main(void)
{
	int i = 0;
	for (putchar('1'); putchar('2'); putchar('3')) {
		putchar('4');
		printf("(%d)\n", ++i);
	}

	return 0;
}
