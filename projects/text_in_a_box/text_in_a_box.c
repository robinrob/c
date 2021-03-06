/* Takes some text and arranges it into a box. */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXSTRING 100

int main(void)
{
	char c, text[MAXSTRING];
	int width, text_length, i, j, cnt = 0;

	//Receives and stores some text
	printf("Enter some text: ");
	for (i = 0; (c = getchar()) != '\n'; ++i) {
		text[i] = c;
	}
	text_length = i;
	
	//Receives width of box and checks value is valid
	printf("Enter width of box: ");
	scanf("%d", &width);
	if (width < 1) {
		printf("width must be 1 or greater");
		exit(0);
	}

	printf("\n");
	
	//Prints top edge of text box which is made of #'s*/
	for (j = 1; j <= (width + 4); ++j)
		printf("#");
	printf("\n# ");
	
	//Prints the text in lines of width specified above, bordered by #'s
	for (i = 0; i < text_length; ++i) {
		printf("%c", text[i]);
		++cnt;
		if ((((cnt % width) == 0)) && (cnt != text_length))
			printf(" #\n# ");
	}
	//Fills in any remaining empty space before right-hand edge of box
	if ((cnt % width) != 0) 
		for ((j = (width - (cnt % width))); (j > 0); --j)
			printf(" ");

	printf(" #\n");
	
	//Prints bottom edge of box
	for (j = 1; j <= (width + 4); ++j)
		printf("#");
	printf("\n\n");

	return 0;
}
