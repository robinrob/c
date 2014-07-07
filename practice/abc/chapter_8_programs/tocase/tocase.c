/* Comparing usage of traditional C tolower() and toupper() with
 * ANSI c _tolower() and _toupper(). */
 
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("toupper('a'): %c\n", toupper('a'));
	printf("_toupper('a'): %c\n", _toupper('a'));
	printf("tolower('A'): %c\n", _tolower('A'));
	printf("_tolower('A'): %c\n", tolower('A'));
	return 0;
}
