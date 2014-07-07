/* Tests return value of printf function. */

#include <stdio.h>

int main(void)
{
	int cnt;

	cnt = printf("abc\0abc\0\n");
	printf("Number of characters printed: %d\n", cnt);

	return 0;
}
