/*
 * kepler.h
 *
 *  Created on: Dec 8, 2010
 *      Author: user
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

typedef double dbl;

extern int cnt;
extern const dbl eps;
extern const dbl e;
extern const dbl m;

dbl bisection(dbl f(dbl x), dbl a, dbl b);
dbl kepler(dbl x);
