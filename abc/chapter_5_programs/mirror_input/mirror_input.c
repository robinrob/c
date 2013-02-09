/* Uses a recursive function to reverse input text. */

#include <stdio.h>

void write_it(void);

int main(void)
{
	printf("Enter some text and press enter: ");
	write_it();
	printf("\n");
	return 0;
}

void write_it(void)
{
	char c;

	if ((c = getchar()) != '\n' && c != EOF)
		write_it();
	if (c != '\n')
		putchar(c);
}
