#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int a);

int main(void)
{
	int a;
	srand(time(NULL));
	a = rand();
	printf("%14s", "a: ");
	bit_print(a);
	a = reverse(a);
    printf("%14s", "a reversed: ");
	bit_print(a);
	return 0;
}

int reverse(int a)
{
	int i, m, b = 0, mask = (1 << (sizeof(int) * CHAR_BIT) - 1);
	//printf("mask: ");
	//bit_print(mask);
	m = 1;
	for (i = 0; i < sizeof(int) * CHAR_BIT; ++i, m *= 2) {
		if (a & mask) {
			b += m;
		}
		a <<= 1;
	}
	return b;
}
