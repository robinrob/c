/* Testing a recursive function to find greatest common divisor. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int, int);

int main(void)
{
	int n, m;
	//printf("Enter two intgers: ");
	//scanf("%d%d", &n, &m);
	srand(time(NULL));
	n = (int) rand()/ 10000000 + 1;
	m = (int) rand()/ 10000000 + 1;
	printf("Greatest common divisor of %d & %d: %d\n", n, m, gcd(n, m));
	return 0;
}

int gcd(int n, int m)
{
	int r;
	if (!(n % m))
		return m;
	else
		return gcd(m, n % m);
}
