/* Bit print an expression. */

#include <limits.h>
#include <stdio.h>

void bit_print(int a);

int main(void)
{
	int a;
	while (scanf("%d", &a) == 1) {
		bit_print(a);
	}
	return 0;
}

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
