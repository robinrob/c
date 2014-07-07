/* A program to demonstrate use of structures and pointers to structures,
 * and how to access member data from each. */

#include <stdio.h>

//Complex number structure
struct complex {
  double re;
  double im;
};

//New type complex
typedef struct complex complex;

void add(complex *a, complex *b, complex *c);
void multiply_p(complex *a, complex *b, complex *c);
complex multiply(complex b, complex c);

int main(void)
{
    complex a, b, c;
    
    b.re = 1;
    b.im = 2;
    c.re = 3;
    c.im = 4;
    add(&a, &b, &c);
    printf("b + c: a: %.4lf + %.4lfi\n", a.re, a.im);
    multiply_p(&a, &b, &c);
    printf("b * c: a: %.4lf + %.4lfi\n", a.re, a.im);
    a = multiply(b, c);
    printf("b * c (2): a: %.4lf + %.4lfi\n", a.re, a.im);
    return 0;
}

//Assigns to a the sum of b and c.
void add(complex *a, complex *b, complex *c)
{
    a -> re = b -> re + c -> re;
    a -> im = b -> im + c -> im;
}

//Assigns to a the product of b and c.
void multiply_p(complex *a, complex *b, complex *c)
{
    a -> re = b -> re * c -> re - b -> im * c -> im;
    a -> im = b -> re * c -> im + b -> im * c -> re;
}

//Assigns to a the product of b and c and returns a;
complex multiply(complex b, complex c)
{
    complex a;
    
    a.re = b.re * c.re - b.im * c.im;
    a.im = b.re * c.im + b.im * c.re;
    return a;
}

