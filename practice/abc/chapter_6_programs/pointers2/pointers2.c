/* Some arithmetic operations with pointers
 * pointers2.c */

#include <stdio.h>

void printHello(void);

int main(void)
{
	int i = 3, j = 5, *p = &i, *q = &j, *r;
	double x;

	printf("%s%d\n%s%d\n%s%p\n%s%d\n%s%d\n",
			"p == &i: ", p == &i,   //1
			"* * & p: ", * * & 	p,  //3
			"r = &x: ", r = &x,   	//address of x
			"7 * *p / *q + 7: ", 7 * * p / * q + 7,  //11
			"* (r = &j) *= *p: ", * (r = &j) *= *p); //15

	void *y = &printHello;
	void *z = &main;
	printf("\nSome interesting pointer assignments!");
	printf("\n%p\n%p\n%p\n%p\n", y, &y, z, &z);

	printf("\nSome interesting pointer facts:");
	printf("\n%s%p\n%s%d\n%s%p\n", "p: ", p, "*p: ", *p, "&p: ", &p);

	return 0;
}

void printHello(void)
{
	printf("Hello!\n");
}
