/* Comparison of increment operator acting on a pointer with
 * use on a dereferenced pointer (to a char array) */

#include <stdio.h>

int main(void)
{
	char a[] = "abcd";
	char *p;
	int i, n = 4;
	
	p = a;
	for (i = 0; i < n; ++i) {
		printf("%c\n", *(p++));
	}
	printf("a = %s\n", a);
	p = a;
	for (i = 0; i < n; ++i) {
		printf("%c\n", (*p)++);
	}
	printf("a = %s\n", a);
	
	return 0;
}
