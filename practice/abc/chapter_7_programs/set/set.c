/* Stores and displays sets using long integers. */

#include <stdio.h>

typedef unsigned long set;
void display(set s);
set Union(set a, set b);

int main(void)
{
	set a = 0x7, b = 0x55;
	printf("set a has elements: ");
	display(a);
	printf("set b has elements: ");
	display(b);
	printf("union(a, b) has elements: ");
	display(Union(a, b));
	return 0;
}

void display(set s)
{
	int i;
	long mask = 1;
	for (i = 0; i < 32; ++i, mask <<= 1) {
		if ((s & mask) == mask) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");
}

set Union(set a, set b)
{
	set union_set = a | b;
	return union_set;
}
