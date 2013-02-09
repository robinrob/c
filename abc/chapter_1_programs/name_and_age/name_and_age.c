/* Asks for the user's name & age and prints a message. */

#include <stdio.h>
#include <stdlib.h>

#define MAXSTRING 20 //max length of input name.

int main(void)
{
	char name[MAXSTRING], c;
	int age, i;

	printf("What is your name?: ");
	i = 0;
	while ((c = getchar()) != '\n') {
		name[i] = c;
		++i;
	}
	name[i] = '\0'; //Appends the end-of-string symbol to the name.
	printf("What is your age?: ");
	scanf("%d", &age);
	printf("Hello %s, next year you will be %d years old.\n", name, age + 1);

	return 0;
}
