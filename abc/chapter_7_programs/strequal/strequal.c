/* A function which checks equality of a given string with a given constant string. */

#include <string.h>

int strequal(char *a, const char *b);

int strequal(char *a, const char *b)
{
	int i;
	if (strlen(a) == strlen(b)) {
		for (i = 0; *(a + i) != '\0'; ++i) {
			if (*(a + i) == *(b + i)) {
				continue;
			}
			else {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
