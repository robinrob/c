/* A program to test the 'diff' Unix command. */

#include <stdio.h>

int main(void)
{
	printf("a%cb%cc\n", '\0', '\0');
	//printf("a\0b\0c\n");
}
