/* main.c
 *
 * This program bit-prints a value of each of the primitive types.
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {t_char, t_short, t_int, t_long, t_float, t_double, t_ld} type;

/* Bit-print a value in pointer-to-void with a given number of bits. */
void bit_print(void *n, int n_bits);

int main(void)
{
	char a = 1;
	short int b = 2;
	int c = 3;

	printf("double: %d\n", sizeof(double));

	printf("char:\n");
	bit_print(&a, sizeof(char) * 8);
	printf("short:\n");
	bit_print(&b, sizeof(short) * 8);
	printf("int:\n");
	bit_print(&c, sizeof(int) * 8);

	return 0;
}

/* Bit-print a value in pointer-to-void with a given number of bits. */
void bit_print(void *n, int n_bits)
{
	int i, mask = 1 << (n_bits - 1);

	for (i = 1; i <= n_bits; ++i) {
		switch (n_bits) {
		case sizeof(char) * 8 :
			putchar(((*((char *) n) & mask) == 0) ? '0' : '1');
			break;
		case sizeof(short) * 8:
			putchar(((*((short *) n) & mask) == 0) ? '0' : '1');
			break;
		case sizeof(int) * 8:
			putchar(((*((int *) n) & mask) == 0) ? '0' : '1');
			break;
		default:
			printf("Programmer error!\n");
			exit(0);
			break;
		}
		mask >>= 1;
		if (i % 8 == 0 && i < n_bits)
			putchar(' ');
	}
	putchar('\n');
}

