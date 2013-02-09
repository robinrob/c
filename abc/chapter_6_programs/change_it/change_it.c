/**
 * Demonstration of how you cannot change a pointer to an array by passing it to the following
 * change_it() function. It doesn't work because only a copy of a is passed (call-by-value).
*/

#include <stdio.h>

void change_it(int []);

int *p;
int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	p = a;
	printf("p has the value %p\n", p);
	change_it(&a[0]);
	//p = a;
	printf("p has the value %p\n", p);
	printf("Values in a[]:\n");
	int i;
	for (i = 0; i < 5; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void change_it(int *a)
{
	int i = 777, *q = &i;
	a = q;
}
