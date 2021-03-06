/* Program to test stack implementation. */

#include "stack.h"

int main(void)
{
//    char c;
//    stack stk = {0};
//    printf("Enter some chars to add: ");
//    while ((c = getchar()) != '\n') {
//	push(c, &stk);
//    }
//    printf("The chars you added: ");
//    while (!(empty(&stk))) {
//	printf("%c", pop(&stk));
//    }
//    printf("\n");

	char str[] = "My name is Robin Smith!";
	int i;
	stack s;
	reset(&s);
	printf(" In the string: %s\n", str);
	for (i = 0; str[i] != '\0'; ++i) {
		if (!full(&s)) {
			push(str[i], &s);
		}
	}
	printf("From the stack: ");
	while (!empty(&s)) {
		putchar(pop(&s));
	}
	putchar('\n');
	return 0;
}
