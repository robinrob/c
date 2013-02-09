/* Tests the use of strcpy() to copy the last few characters
 * of a string onto its beginning */
 
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[] = "abcdefghijklmnopqrstuvwxyz";
	char *p = a;
	char *q = a + strlen(a) - 3;
	
	printf("a = %s\n", a);
	strcpy(p, q);
	printf("a = %s\n", a);
	
	return 0;
}
