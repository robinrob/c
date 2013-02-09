/* Test for equality of two pointers initialised as
 * pointing to the same string constant.
 */

#include <stdio.h>

int main(void)
{
	char *p = "abc", *q = "abc";
	
	if (p == q) {
		printf("addresses equal!\n");
	}
	else {
		printf("addresses NOT equal\n");
	}
	
	return 0;
}
