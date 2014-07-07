/* Displays Fibonacci numbers and quotients. */

#include <stdio.h>

#define LIMIT 30

int is_prime(int n);

int main(void)
{
	long f0 = 0, f1 = 1, n, temp;

	printf("%40s%45s\n"
			"%5s%16s%19s%16s%29s\n"
			"%5s%16s%19s%16s%29s\n",
			/* headings */
			"Fibonacci", "Fibonacci",
			"n", "prime?", "number", "prime?", " quotient",
			"--", "------", "---------", "------", "---------");
	printf("%5d%16s%19d%16s\n"
			"%5d%16s%19d%16s\n",
			0, is_prime(0) ? "yes" : "no", 0, is_prime(0) ? "yes" : "no",
			1, is_prime(1) ? "yes" : "no", 1, is_prime(1) ? "yes" : "no"); /* 1st 2 cases */
	for (n = 2; n <= LIMIT; ++n) {
		temp = f1;
		f1 += f0;
		f0 = temp;
		printf("%5ld%16s%19ld%16s%29.16f\n",
				n, is_prime(n) ? "yes" : "no", f1, is_prime(f1) ? "yes" : "no", (double) f1 / f0);
	}
	return 0;
}

int is_prime(int n)
{
	int k;
	for (k = n / 2; k > 1; --k)
		if (!(n % k)) {
			return 0;
		}
	return 1;
}

