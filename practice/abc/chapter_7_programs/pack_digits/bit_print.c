/* Bit print an expression. */

#include <limits.h>
#include <stdio.h>

void bit_print(int a);
void bit_print_char(char c);

void bit_print(int a)
{
	int i;
	int n = sizeof(int) * CHAR_BIT;
	int mask = 1 << (n - 1);
	
	for (i = 1; i <= n; ++i) {
		putchar(((a & mask) == 0) ? '0' : '1');
		a <<= 1;
		if (i % (CHAR_BIT / 2) == 0 && i < n) {
			putchar(' ');
		}
	}
	putchar('\n');
}

void bit_print_char(char c)
{
	int i;
	int n = CHAR_BIT;
	int mask = 1 << (n - 1);
	
	for (i = 1; i <= n; ++i) {
		putchar(((c & mask) == 0) ? '0' : '1');
		c <<= 1;
	}
	putchar('\n');
}
