/* Tells you if a given integer is prime or not. */

#include <stdio.h>

void exit(int);
int isPrime(int);

int main(void)
{
	int n;
	printf("Enter an integer: ");
	if (scanf("%d", &n) != 1) {
		printf("Must enter an integer!\n");
		exit(0);
	}

	int decade_cnt[(n + 10)/ 10];
	int i;

	for (i = 0; i < ((n + 10)/ 10); ++i) {
		decade_cnt[i] = 0;
	}

	for (i = 1; i <= n; ++i) {
		if (isPrime(i)) {
			printf("%d is a prime number\n", i);
			++decade_cnt[i / 10];
		}
	}
	for (i = 0; i < ((n + 10)/ 10); ++i) {
		printf("Primes in the %d's: %d\n", (i * 10), decade_cnt[i]);
	}

	return 0;
}

int isPrime(int n)
{
	int k;
	for (k = n / 2; k > 1; --k)
		if (!(n % k))
			return 0;
	return 1;
}
