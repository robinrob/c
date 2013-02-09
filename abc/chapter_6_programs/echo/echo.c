/* Echos command line arguments to the program. */

#include <stdio.h>

int main(int argc, char *argv[])
{
	register int i;
	for (i = 1; i < argc; ++i)
		printf("%s %s\n", *(argv + i), argv[i]);

	return 0;
}
