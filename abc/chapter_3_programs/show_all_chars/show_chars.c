/* Program to show all ASCII characters. */

#include <stdio.h>

int main(void)
{
    int i;
    for (i = 0; i < 127; ++i) {
	printf("%c", i);
	if (!(i % 10))
	    printf("\n");
    }
    printf("\n");
    return 0;
}
