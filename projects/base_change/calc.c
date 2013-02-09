/*
 * calc.c
 *
 * Functions used in calculating and displaying a generic number string from a
 * decimal input value.
 */

#include "base_change.h"

/* Calculates and displays a string representing the given number num in the
 * given base. e.g. given base = 16 and num = 255, the output is "FF".
 */
void calc_disp_num_string(int num, int base)
{
	int length;			//number of digits in the converted number
	char *digits;			//stores the converted number as a sequence of
							//characters from '0' to '9' to 'A' to 'Z'

	//Simple case where the given base is 1
	if (base == 1)
		digits = calc_num_str_base_one(num, &length);
	//Here is the conversion to a base other than 1
	else
		digits = calc_num_str_other_bases(num, base, &length);

	print_num_string(num, digits, length, base);
}

/* Returns the number string for the given number num in base 1. The length
 * of the string is stored in the given int pointer.
 */
num_string calc_num_str_base_one(int num, int *length)
{
	int i;
	char *digits;	//stores the converted number as a sequence of
					//characters from '0' to '9' to 'A' to 'Z'

	if (num > MAX_STRING)
		num = MAX_STRING;
	digits = calloc(num, sizeof(int));
	for (i = 0; i < num; ++i) {
		*(digits + i) = '0';		//digits is a sequence of '1's of length num
	}
	*length = num;
	return digits;
}

/* Returns the number string for the given number in the given base. The length
 * of the string is stored in the given int pointer.
 */
num_string calc_num_str_other_bases(int num, int base, int *length)
{
	int i;
	int power;	//holds a power of the given base e.g. 8 would be
							//the 3rd power of base 2
	char digit;				//holds a digit of digits
	char *digits;			//stores the converted number as a sequence of

	//For base > 1, find the highest power of the base number we need in
	//order to represent num and store it in power.
	//Record the number of digits required to represent num in new base.
	for (power = 1, *length = 1; power <= (num / base);
						 	 	 ++(*length), power *= base);

	digits = calloc(*length, sizeof(char));

	for (i = 0; power >= 1; power /= base, ++i) {
		digit = num / power;   //digit is the integer factor of power in num
		num -= digit * power;
		if (digit > 9)
			digit = 'A' + digit - 10;	//symbols for bases > 10
		digits[i] = digit;	//record digit in digits
	}
	return digits;
}

/* Calculates and returns the decimal value of the given number string of given
 * length in the given base.
 */
int calc_string_to_num(num_string s, int length, int base)
{
	char c;
	int num, power;

	num = 0, power = 1;
	while (length > 0) {
		c = s[--length];
		int c_val = symbol_val(c);
		if (base == 1 && c == '0')
			++num;
		else if (c_val < base) {
			num += c_val * power;
			power *= base;
			if (power < 0) {
				printf("integer overflow!\n");
				return NULL_INT;
			}
		}
		else {
			printf("invalid character '%c' for base %d.\n", c, base);
			return NULL_INT;
		}
	}
	return num;
}

