/* Program to display addresses of functions. */

#include <stdio.h>
#include <string.h>

void tell_me(int f(void *, void *));

int main(int argc, int *argv)
{
	tell_me(strcmp);
	tell_me(main);
	return 0;
}

void tell_me(int f(void *, void *))
{
	if (f == strcmp) {
		printf("Address of strcmp(): %p\n", f);
	}
	else {
		printf("Function address: %p\n", f);
	}
}
