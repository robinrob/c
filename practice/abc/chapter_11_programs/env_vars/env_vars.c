/* Demonstrates accessing of environment variables
 * and their values.
 */

#include <stdio.h>

int main(int argc, char *argv[], char *env[])
{
	int i;

	for (i = 0; env[i] != NULL; ++i) {
		printf("%s\n", env[i]);
	}

	printf("\n\n------------------------------------------"
			"------------------------------------\n\n");

	printf("%20s%s\n%20s%s\n%20s%s\n%20s%s\n",
			"Name: ", getenv("NAME"),
			"User: ", getenv("USER"),
			"Shell: ", getenv("SHELL"),
			"Home directory: ", getenv("HOME"));

	return 0;
}
