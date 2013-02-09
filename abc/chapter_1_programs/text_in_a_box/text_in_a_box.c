/* Takes some text from the user and arranges it into a box. */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSTRING 100

int main(void)
{
	char c, text[MAXSTRING];
	int width, textLength, i, j, cnt = 0;

	printf("Enter some text: ");
	//Gets the text from the user.
	for (i = 0; (c = getchar()) != '\n'; ++i) {
		text[i] = c;
	}
	textLength = i;

	//Gets the width the of box from the user.
	printf("Enter width of box: ");
	scanf("%d", &width);
	if (width < 1) {
		printf("\nWidth must be >= 1\n");
		exit(0);
	}

	//Draws the box.
	printf("\n");
	//Top of the box.
	for (j = 1; j <= (width + 4); ++j)
		printf("#");
	printf("\n# ");
	//Contents and sides of the box.
	for (i = 0; i < textLength; ++i) {
		printf("%c", text[i]);
		++cnt;
		if ((((cnt % width) == 0)) && (cnt != textLength))
			printf(" #\n# ");
	}
	if ((cnt % width) != 0)
		for ((j = (width - (cnt % width))); (j > 0); --j)
			printf(" ");

	printf(" #\n");
	//Bottom of the box.
	for (j = 1; j <= (width + 4); ++j)
		printf("#");
	printf("\n\n");

	return 0;
}
