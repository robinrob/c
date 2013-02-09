/* Testing output of the preprocessor for understandibility. */

#include <stdio.h>

#define PRINT(x) printf(#x"\n");

int main(void)
{
	PRINT(Hello from main());
	return 0;
}
