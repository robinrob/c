/* Program to remove vowels from input. */

#include <stdio.h>

int is_vowel(char c);
char lower_case(char c);

int main(void)
{
	char c;
	while (scanf("%c", &c) == 1) {
		if (!is_vowel(c)) {
			putchar(c);
		}
	}
	return 0;
}

int is_vowel(char c)
{
	c = lower_case(c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return 1;
	}
	else {
		return 0;
	}
}

char lower_case(char c)
{
	if (c >= 'A' && c <= 'Z') {
		return 'a' + c - 'A';
	} 
}
