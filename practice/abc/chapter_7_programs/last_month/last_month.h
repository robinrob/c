#include <stdio.h>
#include <assert.h>

enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
typedef enum month month;

month last_month(month m);;
void print_month(month m);
