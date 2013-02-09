/* Header file. */

#include <assert.h>
#include <math.h>
#include <stdio.h>

#define N 4

typedef double dbl;
typedef dbl (*pfdd)(dbl);

extern int cnt;
extern const dbl eps;

dbl bisection(pfdd f, dbl a, dbl b);
dbl f1(dbl x);
dbl f2(dbl x);
dbl f3(dbl x);
