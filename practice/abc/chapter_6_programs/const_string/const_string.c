/* Testing array/pointer operations on a constant string. */

#include <stdio.h>

int main(void)
{
	printf("%c%c%c%c%c!\n",
		   "ghi"[1], *("def" + 1),
		   *"abc" + 11, "klm"[1], *"ghi" + 8); //hello!
	return 0;
}
