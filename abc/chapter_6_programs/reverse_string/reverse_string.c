/* Reverses words input to the program. */

#include <stdio.h>
#include <string.h>

#define MAXWORD 50

char* reverse(char *s);

int main(void)
{
	char word[MAXWORD];
	
	while (scanf("%s", word) == 1) {
		printf("%s\n", reverse(word));
	}
	
	return 0;	
}

char *reverse(char *s)
{
	char *p, *q, tmp;
	int n;
	
	n = strlen(s);
	q = (n > 0) ? s + n - 1: s;
	for (p = s; p < q; ++p, --q) {
		tmp = *p;
		*p = *q;
		*q = tmp;
	}
	return s;
}
