/* Testing some weird arithmetic operations. */

#include <stdio.h>

int main(void)
{
	char c = 'A';
	double x = 1e33, y = 0.001;
	int i = 7, j = 7;

	printf("%d %d %d\n", c == 'a', c == 'b', c != 'c');
	//0, 0, 1
	printf("%d\n", c == 'A' && c <= 'B' || 'C');
	//1
	printf("%d\n", 1 != !!c == !!!c);
	//1
	printf("%d\n", x + y > x - y);
	//0

	printf("\n");
	if (i == 1)
		if (j == 2)
			printf("%d\n", i = i + j);
		else
			printf("%d\n", i = i - j);
	printf("%d\n", i);
	//7

	return 0;
}
