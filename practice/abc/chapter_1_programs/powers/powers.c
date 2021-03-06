/* Prints a table of powers of integers. */

#include <stdio.h>

#define ROWS 15
#define COLS 7
#define MAXSTRING 100

int main(void)
{
	int i, j, num;

	printf("   :::::  A TABLE OF POWERS  :::::\n\n");
	printf("%12s%12s%12s%12s%12s%12s%12s\n%12s%12s%12s%12s%12s%12s%12s\n",
			"Integer", "Square", "3rd power", "4th power", "5th power", "6th power", "7th power",
			"-------", "------", "---------", "---------", "---------", "---------", "---------");

	for (i = 1; i <= ROWS; ++i) {
		num = i;
		for (j = 1; j <= COLS; ++j, num *= i)
			printf("%12d", num);
		printf("\n");
	}

	printf("\n");

	return 0;
}
