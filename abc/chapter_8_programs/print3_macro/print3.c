/* A macro called PRINT3 which does a thing. */

#include <stdio.h>

#define PRINT3(x, y, z) printf("x has value %.1f, "	\
	"y has value %.1f and z has value %.1f\n", x, y, z)
	
int main(void)
{
	float x = 1.1, y = 2.2, z = 3.3;
	PRINT3(x, y, z);
	return 0;
}
