/* Testing loop for infinite iteration (don't think so). */

#include <stdio.h>

int main(void)
{
	int i, j, n;

	printf("Input two integers: ");
	scanf("%d%d", &i, &j);
	n = 0;
	while (i * j < 0 && ++i != 7 && j++ != 9) {
		printf("Still going(%d)\n", n);
		n++;
	}
	return 0;
}
