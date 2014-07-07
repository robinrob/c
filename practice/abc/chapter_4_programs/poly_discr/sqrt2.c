/* Calculates square root using Newton-Rhapson method.
 * sqrt2.c
 *
 *  Created on: Jun 22, 2009
 *      Author: user
 */


#define TOL 0.001

double sqrt2(double x)
{
	int i, complex;
	double result;

	result = 1;
	i = 0;
	if (x < 0) {
		printf("\nInput is negative!");
		return 0;
	}
	else if (x == 0.0)
		return 0;
	else
		while ((result * result - x) > TOL || (x - result * result) > TOL) {
			result = 0.5 * (result + x / result);
			++i;
	}

	return result;
}
