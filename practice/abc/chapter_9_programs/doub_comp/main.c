//Typedef for a structure that contains members of type double and complex.

#include <stdio.h>

typedef struct {
    double re;
    double im;
} complex;

typedef union {
    double d;
    complex c;
} doub_or_comp ;

typedef struct {
    int flag;
    doub_or_comp val;
} dc_type;

void print_dc_type(dc_type a);
void add_doub_comp(double d, complex *c);
void mult_doub_comp(double d, complex *c);
void add_comp_doub(complex c, double *d);
void mult_comp_doub(complex c, double *d);

int main(void)
{
    dc_type a;
    
    a.val.d = 3.0;
    a.val.c.im = 1.0;
    print_dc_type(a);

    add_doub_comp(1.4, &a.val.c);
    print_dc_type(a);

    mult_doub_comp(1.4, &a.val.c);
    print_dc_type(a);
    
    add_comp_doub(a.val.c, &a.val.d);
    print_dc_type(a);

    mult_comp_doub(a.val.c, &a.val.d);
    print_dc_type(a);

    return 0;
}

void print_dc_type(dc_type a)
{
    printf("%s%lf\n%s%lf\n%s%lf\n\n",
    		"a.val.d: ", a.val.d,
    		"a.val.c.re: ", a.val.c.re,
    		"a.val.c.im: ", a.val.c.im);
}

void add_doub_comp(double d, complex *c)
{
	c -> re += d;
	c -> im *= d;
}

void mult_doub_comp(double d, complex *c)
{
	c -> re *= d;
	c -> im *= d;
}

void add_comp_doub(complex c, double *d)
{
	*d += (c.re * c.re + c.im * c.im);
}

void mult_comp_doub(complex c, double *d)
{
	*d *= (c.re * c.re + c.im * c.im);
}
