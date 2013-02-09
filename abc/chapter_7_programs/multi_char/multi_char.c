/* Testing storage of multi-byte chars using bit_print. */

#include <stdio.h>

int main(void)
{
	printf("%20s", "bit_print('abc'): ");
	bit_print('abc');
	printf("%20s", "bit_print('abcd'): ");
	bit_print('abcd');
	printf("%20s", "bit_print('\\0'): ");
	bit_print('\0');
	return 0;
}
