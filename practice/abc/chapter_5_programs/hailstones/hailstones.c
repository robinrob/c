/* Making 'hailstones'. */

#include <stdio.h>

void hailstones(int n);

int main(void)
{
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	hailstones(n);
	return 0;
}

void hailstones(int n)
{
	int cunt = 0;
	while (!(n == 1)) {
		if (!(n % 2))
			printf("%d\n", n /= 2), ++cunt;
		else
			printf("%d\n", n = 3 * n + 1), ++cunt;
	}
	printf("number of hailstones: %d\n", cunt);
}
