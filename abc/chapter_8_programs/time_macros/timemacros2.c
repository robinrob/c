/* A program which does the same thing as timemacros1.c but using macros. */

#include <ctype.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	int c;
	
	printf("Clock ticks: %ld\n", (clock)());
	while ((c = getchar()) != EOF) {
		if ((islower)(c)) {
			putchar((toupper)(c));
		}
		else if ((isupper)(c)) {
			putchar((tolower)(c));
		}
		else if ((isdigit)(c)) {
			(putchar)('x');
		}
		else if ((isspace)(c)) {
			(putchar(c)), (putchar)(c);
		}
	}
	printf("Clock ticks: %ld\n", (clock)());
}
