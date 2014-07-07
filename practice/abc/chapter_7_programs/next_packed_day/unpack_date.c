#include "date.h"

void unpack_date(int date)
{
	int day = 0, month = 0, year = 0, i, mask = 1;
	
	for (i = 0; i < 5; ++i) {
		if (date & mask) {
			day += (1 << i);
		}
		mask <<= 1;
	}
	for (i = 0; i < 4; ++i) {
		if (date & mask) {
			month += (1 << i);
		}
		mask <<= 1;
	}
	for (i = 0; i < 7; ++i) {
		if (date & mask) {
			year += (1 << i);
		}
		mask <<= 1;
	}
	printf("%d/%d/%d", day, month, year);
}
