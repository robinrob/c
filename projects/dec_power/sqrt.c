/* Calculates the square root of a number
 * sqrt.c
 *
 *  Created on: Jun 19, 2009
 *      Author: user
 */

#include "decimalPower.h"

double squareRoot(double n, double tol)
{
	int result = n, i = 0, multiplier = 0.5;

	while ((result * result - n > tol) || (n - result * result > tol)) {
		if (result * result - n > 0)
			result -= n * multiplier;
		else
			result += n * multiplier;
		multiplier /= 2;
		++i;
		printf("Result: %lf\n", result);
		printf("i: %d\n", i);
		printf("multiplier: %lf\n", multiplier);
		printf("tol: %lf\n", tol);
	}
	return result;
}
