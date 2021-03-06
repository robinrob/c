/* A program to test whether or not an input character
 * is a tab.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_tab(char c);

int main(void)
{
	char c;
	printf("enter char: ");
	while ((c = getchar()) != EOF) {
		if (is_tab(c)) {
			printf("c is a tab!\n");
		}
		else if (isspace(c)) {
			continue;
		}
		else {
			printf("c is: %c\n", c);
		}
		printf("enter char: ");
	}
	return 0;
}

//Function to test whether or not a character is a tab.
int is_tab(char c)
{
	//ASCII code for a horizontal tab is 9.
	if (c == 9) {
		return 1;
	}
	else {
		return 0;
	}
}
