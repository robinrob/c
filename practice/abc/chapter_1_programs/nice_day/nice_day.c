/* Have a nice day! */

#include <ctype.h>
#include <stdio.h>

#define MAXSTRING 100

char invert_case(char c);

int main(void)
{
	char c, name[MAXSTRING], boolean;
	int i, sum = 0;

	printf("\nHi!  What is your name?  ");
	//Reads in the user's name.
	for (i = 0; (c = getchar()) != '\n'; ++i) {
		name [i] = c;
		if (isalpha(c))
			sum += c;
	}

	name[i] = '\0';
	printf("\n%s%s%s\n%s",
			"Nice to meet you ", name, ".",
			"Your name inverted is ");
	//Displays the inverted name one character at a time.
	for (--i; i >= 0; --i)
		putchar(invert_case(name[i]));

	printf("\n%s%d%s\n\n%s\n",
			"and the letters in your name sum to ", sum, ".",
			"Have a nice day!");
	
	//Checks whether the program's output is correct.
	printf("\nIs this correct? (y or n): ");
	scanf("%c", &boolean);
	if (boolean == 'y')
		printf("Fucking brilliant!\n");

	return 0;
}

//Function to invert the case of a character.
char invert_case(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return ('a' + (c - 'A'));
	else if ((c >= 'a') && (c <= 'z'))
		return ('A' + (c - 'a'));
	else
		return c;
}
