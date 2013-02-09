/*
 * get.c
 *
 * Functions to get input from the user.
 */

#include "base_change.h"

//Gets a base number from the user.
int get_start_base()
{
	return get_int(">Enter start base", 1, MAX_BASE);
}

//Gets a base number from the user.
int get_end_base()
{
	return get_int(">>>Enter end base  ", 1, MAX_BASE);
}

/* Displays a prompt for input and gets an integer from the user from lowest
 * to highest values.
 */
int get_int(const char *prompt, int lowest, int highest)
{
	int n = NULL_INT;

	printf("%s (%d to %d): ", prompt, lowest, highest);
	while (scanf("%d", &n) == 1) {
		if (!(n >= lowest && n <= highest)) {
			printf("number must be from %d to %d!\n", lowest, highest);
			printf("%s (%d to %d): ", prompt, lowest, highest);
			continue;
		}
		else
			break;
	}
	if (n == NULL_INT) {
		getchar();
		getchar();
		return NULL_INT;
	}
	getchar();
	return n;
}

//Gets a number string from the user and returns its decimal int value.
int get_num_as_string(int start_base)
{
	int length = 0;
	num_string s = get_num_string(&length);
	return calc_string_to_num(s, length, start_base);
}

//Gets and returns a number string from the user.
num_string get_num_string(int *length)
{
	char c;
	num_string digits;
	digits = calloc(sizeof(char), MAX_STRING);
	printf(">>Enter digits for number   : ");
	while ((c = getchar()) != '\n') {
		if (!(isalnum(c)))
			error_exit("invalid character");
		digits[(*length)++] = c;
	}
	return digits;
}

//Returns the numeric int value of a number string character.
int symbol_val(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		return c - 'A' + 10;
	else
		return NULL_INT;
}
