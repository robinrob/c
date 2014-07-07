/* Counts types of characters in the input to the program. */

#include <stdio.h>

int main(void)
{
	int letter_cnt = 0, digit_cnt = 0, blank_cnt = 0, newline_cnt = 0, other_cnt = 0;
	char c;
	
	while ((c = getchar()) != EOF)
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			++letter_cnt;
		else if (c >= '0' && c <= '9')
			++digit_cnt;
		else if (c == ' ')
			++blank_cnt;
		else if (c == '\n')
			++newline_cnt;
		else
			++other_cnt;
		
		printf("%s\n%s%d\n%s%d\n%s%d\n%s%d\n%s%d\n", "Numbers of characters:", "letters: ", letter_cnt, "digits: ", digit_cnt, "blanks: ", blank_cnt, "newlines: ", newline_cnt, "others: ", other_cnt);
		
		return 0;
}
