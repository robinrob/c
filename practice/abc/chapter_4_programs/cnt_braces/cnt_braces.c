/* Counts numbers of left and right braces in an input file. */

#include <stdio.h>

int main(void)
{
	int left_cnt = 0, right_cnt = 0, i;
	char c;

	//if (argc != 2)
	//	printf("Usage: %s %s\n", argv[0], "input file");

	while ((c = getchar()) != EOF) {
		putchar(c);
		if (c == '{')
			left_cnt++;
		else if (c == '}')
			right_cnt++;
		if (right_cnt > left_cnt)
			for (i = 1; i < right_cnt - left_cnt; ++i)
				putchar('?'), putchar('?');
	}
	printf("\n");
	if (left_cnt > right_cnt) {
		printf("ERROR: Missing right braces: ");
		for (i = 0; i < left_cnt - right_cnt; ++i)
			putchar('}');
	}
	else if (right_cnt > left_cnt) {
		printf("ERROR: Too many left braces: ");
	for (i = 0; i < right_cnt - left_cnt; ++i)
		putchar('{');
	}
	printf("\n");

	return 0;
}
