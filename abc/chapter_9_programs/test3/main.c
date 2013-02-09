//What gets printed?

#include <stdio.h>

//Note: it still gives the same result without the first a/b in the typedef!
typedef struct a { unsigned a : 1, : 0, b : 1; } a;
typedef struct b { unsigned a : 1, b : 1; } b;

int main(void)
{
	//printf("sizeof(a): %d\n", sizeof(a));
	//printf("sizeof(b): %d\n", sizeof(b));
	printf("ratio:     %.1f\n", (float) sizeof(a) / sizeof(b));

	return 0;
}
