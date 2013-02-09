#include <stdio.h>

void addition(char *a, char b);

int main(void)
{
	char a = 1, b = 2;
	
	printf("a + b: %d\n", a + b);
	printf("a += b: %d\n", a += b);
	addition(&a, b);
	printf("after addition(&a, b): %d\n", a);
	return 0;
}

void addition(char *a, char b)
{
	*a += b;
}
