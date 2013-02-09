#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int a);

int reverse(int a)
{
	int i, m, b = 0, mask = (1 << (sizeof(int) * CHAR_BIT) - 1);
	//printf("mask: ");
	//bit_print(mask);
	m = 1;
	for (i = 0; i < 32; ++i, m *= 2) {
		if (a & mask) {
			b += m;
		}
		a <<= 1;
	}
	return b;
}
