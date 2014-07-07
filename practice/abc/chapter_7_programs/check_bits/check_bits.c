#include <stdio.h>

int main(void)
{
	int i = -1;
	unsigned u = -1;
	
	bit_print(i);
	bit_print(u);
	if (i >> 1 == u >> 1) {
		printf("Zeros are shifted in.\n");
	}
	else {
		printf("Sign bits are shifted in.\n");
	}
	bit_print(i);
	bit_print(u);
	return 0;
}
