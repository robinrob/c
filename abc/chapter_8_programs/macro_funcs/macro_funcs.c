/* Testing availability of functions which are used in macros. */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	if ((isalpha)('a')) {
		printf("Found the isalpha() function!\n");
	}
	if ((isalpha)((getchar)())) {
		printf("Found the getchar() function!\n");
	}
	
	return 0;
}

