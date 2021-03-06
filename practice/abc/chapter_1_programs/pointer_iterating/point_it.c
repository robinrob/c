/*Shows how to iterate over a character array (string) without knowing how long it is.*/

#include <stdio.h>

int main(void)
{
	char a[100], c, *p = a;
	int i;

	//Reading in the array from the user.
	i = 0;
	while (scanf("%c", &c) && (c != '\n')) {
			a[i] = c;
			++i;
	}
	a[i] = '\0';

	//Printing the array to the screen.
	for (; *p != '\0'; ++p)
		printf("%c", *p);

	printf("\n");

	return 0;
}
