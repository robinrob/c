/*
 * calc.h
 *
 */

/* Calculates and displays a string representing the given number num in the
 * given base. e.g. given base = 16 and num = 255, the output is "FF".
 */
void calc_disp_num_string(int num, int base);

/* Returns the number string for the given number num in base 1. The length
 * of the string is stored in the given int pointer.
 */
num_string calc_num_str_base_one(int num, int *length);

/* Returns the number string for the given number in the given base. The length
 * of the string is stored in the given int pointer.
 */
num_string calc_num_str_other_bases(int num, int base, int *length);

/* Calculates and returns the decimal value of the given number string of given
 * length in the given base.
 */
int calc_string_to_num(num_string s, int length, int base);

