/* A test of how the compiler deals with changing the
 * address of a pointer which is initialised pointing
 * to a string constant.
 */

#include <stdio.h>

int main(void)
{
	char *p = "abc";
	
	*p = 'X'; //illegal, produces segmentation fault
	printf("%s\n", p);
	
	return 0;
}
