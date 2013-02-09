/* Checks whether given words are palindromes or not. */

#include <stdio.h>
#include <string.h>

#define MAX_STRING 50

int is_palindrome(char text[], int length);
int charcasecmp(char a, char b);

int main(void)
{
	int i, j, length;
	char c, text[MAX_STRING];
	
	i = 0;
	printf("Enter text: ");
	while ((c = getchar()) != '\n') {
		text[i] = c;
		++i;
	}
	length = i;
	
	if (is_palindrome(text, length)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
	
	return 0;
}

int is_palindrome(char text[], int length)
{
	int i = length - 1, j = 0;
	while (i > length / 2) {
		if (text[i] == ' ') {
			--i;
			continue;
		}
		if (text[j] == ' ') {
			++j;
			continue;
		}
		if (!(charcasecmp(text[i], text[j]))) {
			break;
		}
		--i, ++j;
	}
	if (i == length / 2) {
		return 1;
	}
	else {
		return 0;
	}
}

int charcasecmp(char a, char b)
{
	if (a >= 'A' && a <= 'Z') {
		a = a - 'A' + 'a';
	}
	if (b >= 'A' && b <= 'Z') {
		b = b - 'A' + 'a';
	}
	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}

