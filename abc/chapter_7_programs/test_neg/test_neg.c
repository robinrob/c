/* Testing the machine's implementation of negative integers. */

#include <stdio.h>

int main(void)
{
	int i = 255;
	printf("complement of i: %d\n", ~(i));
	printf("negative of i: %d\n", ~(i - 1));
	
	return 0;
}
