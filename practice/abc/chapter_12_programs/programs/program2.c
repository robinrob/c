/* Program 2, which will be overlaid with program 1. */

#include <stdio.h>

int main(int argc, char **argv)
{
	int i, sum = 0, value;

	for (i = 1; i < argc; ++i) {
		if (sscanf(argv[i], "%d", &value) == 1) {
			sum += value;
		}
		printf("%s: sum of command line args = %d\n", argv[0], sum);
	}
	return 0;
}
