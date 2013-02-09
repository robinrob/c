/* A function which parses an int from an input string. */

#include <stdio.h>
#include <string.h>

#define MAX_STRING 10

int parse_int(char s[], int n);

int main(void)
{
	char s[MAX_STRING];
	int a, n = 0;
	printf("Enter an integer: ");
	scanf("%s", s);
	while (s[n] != '\0') {
		++n;
	}
	a = parse_int(s, n - 1);
	printf("Parsed int: %d\n", a);
	return 0;
}

int parse_int(char s[], int n)
{
	int i, factor = 1, a = 0;
	for (i = n; i >= 0; --i, factor *= 10) {
		a += ((s[i]) - '0') * factor;
	}
	return a;
}
