/* Packs a string of 8 (4-bit) digits into an int. */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>

char* unpack(int a);
int pack(char *c);

int main(void)
{
	int i;
	unsigned int a;
	char *c = calloc(8, sizeof(char));
	printf("Enter a string of 8 digits: ");
	for	(i = 0; i < 8; ++i) {
		*(c + i) = getchar() - '0';
	}
	a = pack(c);
	printf("packed digits: ");
	bit_print(a);
	printf("unpacked digits: ");
	c = unpack(a);
	for	(i = 0; i < 8; ++i) {
		putchar(*(c + i));
	}
	printf("\n");
	free(c);
	return 0;
}

int pack(char *c)
{
	int i, j;
	unsigned int a, b = 0, m, mask;
	m = mask = (1 << (sizeof(int) * CHAR_BIT - 1));
	
	for (i = 0; i < 8; ++i) {
		a = reverse(*(c + i) - '0');
		for (j = 4; j >= 1; --j) {
			if (a & mask) {
				b += (m >> (j - 1));
			}
			a <<= 1;
		}
		m >>= 4;
	}
	return b;
}

char* unpack(int a)
{
	int i, j;
	unsigned int mask = (1 << (sizeof(int) * CHAR_BIT - 1));
	char *c = calloc(sizeof(char), 8);
	for (i = 0; i < 8; ++i) {
		*(c + i) = '0';
		for (j = 8; j >= 1; j /= 2) {
			if (a & mask) {
				*(c + i) += j;
			}
			a <<= 1;
		}
	}
	return c;
}
