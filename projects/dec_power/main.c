/* Computes powers.
 * power.c
 *
 *  Created on: Jun 23, 2009
 *      Author: user
 */

#include "decimalPower.h"

int main(void)
{
	double n;

	printf("Enter a real number to calculate its fourth root: ");
	scanf("%lf", &n);
	printf("Fourth root of %lf: %lf\n", n, fourthRoot(n, TOL));
	return 0;
}

double fourthRoot(double n, double tol)
{
	return sqrt(sqrt(n));
}

