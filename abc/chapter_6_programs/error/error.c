/* This program has an error in it which is compiler-dependent. */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *p1 = "abc", *p2 = "pacific sea";
	
	printf("%s  %s  %s\n", p1, p2, strcat(p1, p2));
	return 0;
}
