#include <stdio.h>

int main(void)
{
	int i;
	int a[4] = {0xff, 0xff00, 0xff0000, 0xff000000};
	for (i = 0; i < 4; ++i) {
		printf("%10x bit-printed: ", a[i]);
		bit_print(a[i]);
	}
	return 0;
}
