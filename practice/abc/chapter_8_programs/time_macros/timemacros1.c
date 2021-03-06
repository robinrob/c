/* A program which does some operations using string functions,
 * to be compared to timemacros2.c. However both programs run
 * instantaneously of course.
 */

#include <ctype.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	int c;
	
	printf("Clock ticks: %f\n", clock());
	while ((c = getchar()) != EOF) {
		if (islower(c)) {
			putchar(toupper(c));
		}
		else if (isupper(c)) {
			putchar(tolower(c));
		}
		else if (isdigit(c)) {
			putchar('x');
		}
		else if (isspace(c)) {
			putchar(c), putchar(c);
		}
	}
	printf("Clock ticks: %f\n", clock());
}
