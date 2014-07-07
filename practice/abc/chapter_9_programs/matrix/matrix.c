/* Demonstrates addition and multiplication of two matrices using only 1-densional
 * arrays to store them.
 */

#include <stdio.h>
#include <stdlib.h>
#include "time_keeper.c"

#define RANK 4

typedef int * matrix;

void print_m(matrix a, int rank);
void add(matrix a, matrix b, matrix c, int rank);
void multiply(matrix a, matrix b, matrix c, int rank);

int main(void)
{
    int i, j;
    matrix a, b, c;
    
    a = calloc(RANK * RANK, sizeof(int));
    b = calloc(RANK * RANK, sizeof(int));
    c = calloc(RANK * RANK, sizeof(int));
    
    for (i = 0; i < RANK * RANK; ++i) {
	a[i] = i + 1;
	b[i] = i + 5;
    }
    
    printf("matrix a:\n");
    print_m(a, RANK);
    printf("matrix b:\n");
    print_m(b, RANK);
    
    add(a, b, c, RANK);
    printf("a + b:\n");
    print_m(c, RANK);
    
    multiply(a, b, c, RANK);
    printf("a x b:\n");
    print_m(c, RANK);
    start_time();
    print_time();
        
    return 0;
}

//Prints a square matrix of given rank.
void print_m(matrix a, int rank)
{
    int i, j;
    for (i = 0; i < rank * rank; ++i) {
	printf("%2d ", a[i]);
	if (((i + 1) % rank) == 0) {
	    printf("\n");
	}
    }
    printf("\n");
}

//Adds square matrices a and b and stores the result in c.
void add(matrix a, matrix b, matrix c, int rank)
{
    int i;
    for (i = 0; i < rank * rank; ++i) {
	c[i] = a[i] + b[i];
    }
}

//Mulitplies square matrices a and b and stores the result in c.
void multiply(matrix a, matrix b, matrix c, int rank)
{
    int i,j, k;
    for (i = 0; i < rank * rank; ++i) {
	c[i] = 0;
	for (j = 0; j < rank; ++j) {
	    c[i] += a[i / rank * rank + j] * b[i % rank + j * rank];
	}
    }
}
