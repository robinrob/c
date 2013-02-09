#include "largeText.h"

#define DURATION 1

int main(void)
{
	int i, mask = 1, t0;
	
	for (i = 0; i < 10; ++i) {
		i & mask ? printL() : printO();
		t0 = clock();
		while(((clock() - t0) / 1000000.0) < DURATION);
	}
	return 0;
}
