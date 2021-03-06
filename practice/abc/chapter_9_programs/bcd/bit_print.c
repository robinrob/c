/* Bit print an expression. */

#include "bcd.h"

//Bit-prints n bits of the given integer a.
void bit_print(int a, int n_bits)
{
	int i;
	int mask = 1 << (n_bits - 1);
	
	for (i = 1; i <= n_bits; ++i) {
		putchar(((a & mask) == 0) ? '0' : '1');
		a <<= 1;
		if ((i % (CHAR_BIT) == 0) && i < n_bits) {
			putchar(' ');
		}
	}
	printf(" ");
}
