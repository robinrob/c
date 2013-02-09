/* main.c
 *
 * This program takes as input an integer starting base, a string of
 * alphanumeric characters representing a number in the starting base,
 * then requests an end base. It then displays the given number in the end base.
 */

#include "base_change.h"

int main(void)
{
	int start_base, end_base;
	unsigned int num;

	print_message();

	while ((start_base = get_start_base()) != NULL_INT)
		while ((num = get_num_as_string(start_base)) != NULL_INT)
			while ((end_base = get_end_base()) != NULL_INT)
				calc_disp_num_string(num, end_base);


	printf("\nBye!\n");
	return 0;
}



