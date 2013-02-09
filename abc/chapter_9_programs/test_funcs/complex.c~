/* A program which times two versions of a function to multiply complex numbers -
 * one which uses call-by-value and another which uses pointer addresses.
 */

#include <stdio.h>
#include <stdlib.h>
#include "time_keeper.c"

#define N_NUMS 100000
#define N_REPS 1000

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
    int i, j;
    complex a, b[N_NUMS], c[N_NUMS];
    
    srand(time(NULL));
    
    //Create N_NUMS complex numbers in arrays b and c.
    for (j = 0; j < N_NUMS; ++j) {
	    b[j].re = b[j].im = rand() % 1000;
	    c[j].re = c[j].im = rand() % 1000;
    }
    
    printf("Pointer version:\n");
    start_time();
    /* Multipy all the complex numbers in arrays b
     * and c using multiply_p() and do this N_REPS times.
     */
    for (i = 0; i < N_REPS; ++i) {
	for (j = 0; j < N_NUMS; ++j) {
	    multiply_p(&a, &b[j], &c[j]);
	}
    }
    print_time();
    
    printf("\nOther version:\n");
    start_time();
    /* Multipy all the complex numbers in arrays b
     * and c using multiply() and do this N_REPS times.
     */
    for (i = 0; i < N_REPS; ++i) {
	for (j = 0; j < N_NUMS; ++j) {
	    a = multiply(b[j], c[j]);
	}
    }
    print_time();
    
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

