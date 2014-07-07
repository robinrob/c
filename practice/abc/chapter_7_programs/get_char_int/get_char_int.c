/* A test to see if an integer can be used to store either an
 * integer or a character input by the user. */

#include <stdio.h>

int main(void)
{
	int a = 0;
	printf("Enter a character: ");
	scanf("%c", &a);
	printf("int a: %d\n", a);
	printf("char a: %c\n", (char) a);
	printf("bits of a: ");
	bit_print(a);
	
	a = 0;
	printf("Enter an integer: ");
	scanf("%d", &a);
	printf("int a: %d\n", a);
	printf("char a: %c\n", (char) a);
	printf("bits of a: ");
	bit_print(a);
	return 0;
}
