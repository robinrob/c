/* Packs four characters into an int. */

#include <stdio.h>
#include <limits.h>

int pack(char a, char b, char c, char d);
void unpack(int n);
char unpack2(int n, int k);
void bit_print(int a);

int main(void)
{
	int i, b;
	char c, arr[4];
	
	printf("Enter four characters: ");
	i = 0;
	while (i < 4) {
		if (scanf("%c", &c) == 1) {
			arr[i] = c;
			++i;
		}
	}
	b = pack(arr[0], arr[1], arr[2], arr[3]);
	printf("\nChars packed into an int: %d\n", b);
	printf("Or: ");
	bit_print(b);
	printf("\n");
	
	printf("\nUnpacked int: ");
	unpack(b);
	printf("\n");
	
	printf("Or: ");
	for (i = 3; i >= 0; --i) {
		printf("%c ", unpack2(b, i));
	}
	printf("\n");
	
	return 0;
}

int pack(char a, char b, char c, char d)
{
	return (((((int) a) << CHAR_BIT) | b) << CHAR_BIT | c) << CHAR_BIT | d;
}

void unpack(int n)
{
	int i = 0;
	int mask = -1;
	while (i < 4) {
		printf("%c ", n & mask);
		n >>= CHAR_BIT;
		++i;
	}
}

char unpack2(int a, int k)
{
	int n = k * CHAR_BIT;
	unsigned int mask = 255;
	
	mask <<= n;
	return ((a & mask) >> n);
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
