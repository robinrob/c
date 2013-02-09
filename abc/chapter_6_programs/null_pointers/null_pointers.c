/**
 * This program demonstrates how the value of NULL is stored and used. Pointers
 * of various types are assigned to point to the NULL value, then the memory
 * address differences from each type of pointer to other available spaces are
 * displayed. It shows that every pointer type points to the same memory address
 * where NULL is located.
**/

#include <stdio.h>

typedef unsigned long ulong;

int main(void)
{
	char *pc = NULL;
	int *pi = NULL;
	double *pd = NULL;
	long double *pld = NULL;
	
	printf("%5lu%5lu\n%5lu%5lu\n%5lu%5lu\n",
		   (ulong)(pc + 1), (ulong)(pi + 1), //00
		   (ulong)(pd + 1), (ulong)(pld + 1), //0garbage
		   (ulong)(pc + 3), (ulong)(pld + 3)); //0garbage
	
	return 0;
}
