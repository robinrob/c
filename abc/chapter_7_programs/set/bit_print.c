/* Bit print an expression. */

#include <limits.h>
#include <stdio.h>

void bit_print(long a);

void bit_print(long a)
{
	int i;
	int n = sizeof(long) * CHAR_BIT;
	int mask = 1 << (n - 1);
	
	for (i = 1; i <= n; ++i) {
		putchar(((a & mask) == 0) ? '0' : '1');
		a <<= 1;
		if (i % (CHAR_BIT) == 0 && i < n) {
			putchar(' ');
		}
	}
	putchar('\n');
}
