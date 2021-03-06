/* Reads input and displays large text
 * playText.c
 *
 *  Created on: Feb 1, 2010
 *      Author: user
 */

#include "large_text.h"

#define MAXSTRING 50
#define DURATION 0.4

char to_lower(char);
void drawLetter(void f(void));

extern pfv alph_arr[];

int main(void)
{
	char c, text[MAXSTRING];
	int textLength, i, j, cnt = 0;
	float start, finish, t0;
	int start_int;
	int finish_int;

	printf("Enter some text: ");
	for (i = 0; (c = getchar()) != '\n'; ++i) {
		text[i] = c;
	}
	textLength = i;

	for (i = 0; i < textLength; ++i) {
		if (text[i] == ' ')
			continue;
		t0 = clock();
		while(((clock() - t0) / 1000000.0) < DURATION);
		c = to_lower(text[i]);
		drawLetter(alph_arr[c - 'a']);
	}

	return 0;
}

char to_lower(char c)
{
	assert (isalpha(c));
	if (c >= 'A' && c <= 'Z')
		return 'a' + (c - 'A');
	else {
		return c;
	}
}

void drawLetter(void f(void))
{
	f();
}
