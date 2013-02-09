/*
 * print.c
 *
 *  Printing functions.
 */

#include "base_change.h"

/* Prints the start message for the program */
void print_message(void)
{
	printf("\n%s\n\n",
			"-------------------------------------------------------------\n"
			"This program will take a given number in a given initial\n"
			"base representation and convert it into another given base\n"
			"representation.\n\n"
			"To go back to the previous prompt, type 'q' for the 'base'\n"
			"prompts and press 'enter' for the 'number' prompt.\n\n"
			"Try the following inputs:\n"
			"start base: 2\n"
			"digits    : 10110001010100101101001111\n"
			"end base  : 36\n"
			"-------------------------------------------------------------\n");
}

/* Displays a number string of given length representing a decimal number num
 * in the given base.
 */
void print_num_string(int num, num_string s, int length, int base)
{
	int i;
	printf("\n%5d%s%2d: ", num, " displayed in base ", base);
		for (i = 0; i < length; ++i) {
			s[i] <= 9 ? printf("%d", s[i]) : printf("%c", s[i]);
		}
	printf("\n\n");
	free(s);
}

