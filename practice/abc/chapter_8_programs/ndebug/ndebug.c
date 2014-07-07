//Ignorning assert statements by defining NDEBUG

#include <assert.h>

#define NDEBUG

#include <assert.h>
#include <stdio.h>

int main(void)
{
	int a = 0;
	assert(a != 0);
	printf("assert was ignored!\n");
	return 0;
}
