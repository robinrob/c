/* Reads input from standard input file and counts
 * numbers of characters and numbers. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c;
	int characters = 0, numbers = 0;

	while ((scanf("%c", &c)) == 1) {
		if (c >= '0' && c <= '9')
			++numbers;
		else
			++characters;
	}

	printf("\n%-20s%d\n%-20s%d\n", "Number of characters: ", characters,
			"Number of numbers: ", numbers);

	return 0;
}
