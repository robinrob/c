/* Using conditional expressions for min(x, y, z). */

#include <stdio.h>

double min(double, double, double);
double max(double, double, double);

int main(void)
{
	double x, y, z;

	printf("Enter doubles for x, y, z: ");
	scanf("%lf%lf%lf", &x, &y, &z);
	printf("min(x, y, z): ");
	if (min(x, y, z) == x)
		putchar('x');
	else if (min(x, y, z) == y)
		putchar('y');
	else if (min(x, y, z) == z)
			putchar('z');
	else
		printf("ERROR!");
	printf("\n");

	printf("max(x, y, z): ");
	if (max(x, y, z) == x)
		putchar('x');
	else if (max(x, y, z) == y)
		putchar('y');
	else if (max(x, y, z) == z)
			putchar('z');
	else
		printf("ERROR!");
	printf("\n");

	return 0;
}

double min(double x, double y, double z)
{
	return x < y ? (x < z ? x : z) : (y < z ? y : z);
}
double max(double x, double y, double z)
{
	return x > y ? (x > z ? x : z) : (y > z ? y : z);
}
