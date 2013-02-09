//Binary Coded Decimal implementation

#include "bcd.h"

int main(void)
{
	bcd num = {1, 2, 3, 4, 5, 6, 7, 8};

	printf("%-20s", "printed as BCD:");
	bit_print_bcd(num);
	printf("%-20s", "printed as decimal:");
	dec_print_bcd(num);
	printf("%-20s", "printed as binary:");
	bit_print(bcd_to_dec(num), 32), putchar('\n');
	printf("%-20s%d\n", "as actual decimal:", bcd_to_dec(num));


	return 0;
}

/* Prints the value of a binary coded decimal variable
 * as a decimal.
 */
void dec_print_bcd(bcd a)
{
	printf("%d%d%d%d%d%d%d%d\n",
			a.a, a.b, a.c, a.d,
			a.e, a.f, a.g, a.h);
}

//Bit-prints the value of a binary coded decimal variable.
void bit_print_bcd(bcd a)
{
	bit_print(a.a, 4);
	bit_print(a.b, 4);
	bit_print(a.c, 4);
	bit_print(a.d, 4);
	bit_print(a.e, 4);
	bit_print(a.f, 4);
	bit_print(a.g, 4);
	bit_print(a.h, 4);
	printf("\n");
}

//Converts a BCD to a decimal number and returns it as an int.
int bcd_to_dec(bcd a)
{
	int dec = 0, power = 10, i;

	//Set power equal to 10^7.
	for (i = 0; i < 6; ++i) {
		power *= 10;
	}

	dec += a.a * power;
	power /= 10;
	dec += a.b * power;
	power /= 10;
	dec += a.c * power;
	power /= 10;
	dec += a.d * power;
	power /= 10;
	dec += a.e * power;
	power /= 10;
	dec += a.f * power;
	power /= 10;
	dec += a.g * power;
	power /= 10;
	dec += a.h * power;

	return dec;
}
