#include <stdio.h>

void set_bit(int n, int val, char *bool);
int b_val(int n, char b);

int main(void)
{
	char a = 16;
	printf("5th bit: %d\n", b_val(5, a));
	set_bit(5, 0, &a);
	printf("5th bit: %d\n", b_val(5, a));
	set_bit(5, 1, &a);
	printf("5th bit: %d\n", b_val(5, a));
	set_bit(5, 0, &a);
	printf("5th bit: %d\n", b_val(5, a));
	set_bit(5, 1, &a);
	printf("5th bit: %d\n", b_val(5, a));
	return 0;
}

void set_bit(int n, int val, char *bool)
{
	char mask = (1 << (n - 1));
	if (val && !(*bool & mask)) {
		*bool += mask;
	}
	else if (!val && (*bool & mask)) {
		*bool -= mask;
	}
}

int b_val(int n, char b)
{
	return (b & (1 << (n - 1))) ? 1 : 0;
}
