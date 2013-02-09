/* Testing the constant-ness of a constant char pointer */

#include <stdio.h>

int main(void)
{
	char s[] = "abc";
	const char *p =s;
	
	*p = 'A'; //compiler error
	printf("%s\n", p);
	
	return 0;	
}
