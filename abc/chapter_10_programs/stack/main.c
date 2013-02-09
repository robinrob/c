/* Test the stack implementation by reversing a string. */

#include "stack.h"

int main(void)
{
	char str[] = "My name is Robin Smith!";
	int i;
	stack s;

	printf("The string:     %s\n", str);
	initialise(&s);
	for (i = 0; str[i] != '\0'; ++i) {
		if (!full(&s))
			push(str[i], &s);
	}

	printf("From the stack: ");
	while (!empty(&s)) {
		putchar(pop(&s));
	}
	putchar('\n');

	return 0;
}
