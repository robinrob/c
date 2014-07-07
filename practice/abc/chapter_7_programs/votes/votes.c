/* Calculating the majority of a set of votes from different people
 * which are stored as bits in integers */
 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void bit_print(int a);
short majority (short a, short b, short c);

int main(void)
{
	short int a, b, c, d;
	srand(time(NULL));
	a = (rand() % 32767) - 32767;
	b = (rand() % 32767) - 32767;
	c = (rand() % 32767) - 32767;
	d = (rand() % 32767) - 32767;
	printf("a: %d\nb: %d\nc: %d\nd: %d\n", a, b, c);
	printf("%10s", "a:");
	bit_print(a);
	printf("\n");
	printf("%10s", "b:");
	bit_print(b);
	printf("\n");
	printf("%10s", "c:");;
	bit_print(c);
	printf("\n");
	printf("\n%10s", "Majority:");
	bit_print(majority(a, b, c));
	printf("\n");
	return 0;
}

short majority (short a, short b, short c)
{
	return ((a & b) | c);
}

void bit_print(int a)
{
	int i;
	int n = sizeof(int) * CHAR_BIT;
	int mask = 1 << (n - 1);
	
	for (i = 1; i <= n; ++i) {
		putchar(((a & mask) == 0) ? '0' : '1');
		a <<= 1;
		if (i % CHAR_BIT == 0 && i < n) {
			putchar(' ');
		}
	}
}
