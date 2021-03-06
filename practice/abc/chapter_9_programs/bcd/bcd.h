//Header file for the bcd project.

#include <stdio.h>
#include <limits.h>

typedef struct {
	unsigned a: 4, b: 4, c: 4, d: 4, e: 4, f: 4, g: 4, h: 4;
} bcd;

void dec_print_bcd(bcd a);
void bit_print_bcd(bcd a);
void bit_print(int a, int n_bits);

int bcd_to_dec(bcd a);
