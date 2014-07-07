/* Using the sizeof operator on arrays and other things within the
 * main program and within functions. Whenever sizeof is used on a
 * pointer (or an explicit address) the result is a size of 4 bytes
 * - because addresses are stored in 4 bytes.
 */

#include <stdio.h>

void f(int a[]);
void fd(double a[]);

int main(void)
{
	char s[] = "deep in the heart of texas";
	char *p = "deep in the heart of texas";
	char c = 'c';
	int a[7];
	double d[5];
	
	printf("%s%d\n%s%d\n%s%d\n%s%d\n%s%d\n",
		   "sizeof(s) = ", sizeof(s),
		   "sizeof(c) = ", sizeof(c),
		   "sizeof(p) = ", sizeof(p),
		   "sizeof(a) = ", sizeof(a),
		   "sizeof(d) = ", sizeof(d));
		   
	f(a);
	fd(d);
	return 0;
}

void f(int a[])
{
	printf("In f(): sizeof(a) = %d\n", sizeof(a));
}

void fd(double a[])
{
	printf("In f(): sizeof(d) = %d\n", sizeof(a));
}
