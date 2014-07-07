/* Testing a basic macro. */

#include <stdio.h>

#define TRY_ME 5

int main(void)
{
	printf("TRY_ME: %d\n", TRY_ME);
	#undef TRY_ME
	printf("TRY_ME: %d\n", TRY_ME);
	return 0;
}
