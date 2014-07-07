#include "date.h"

int pack_date(int day, int month, int year)
{
	assert(day >= 0 && day <= 31);
	assert(month >= 0 && month <= 12);
	
	short date = 0;
	pack_day(day, &date);
	pack_month(month, &date);
	pack_year(year, &date);
	
	return date;
}

void pack_day(int day, short *date)
{
	int i, mask = 1;
	for (i = 0; i < 5; ++i) {
		if (day & mask) {
			*date += (1 << i);
		}
		day >>= 1;
	}
}

void pack_month(int month, short *date)
{
	int i, mask = 1;
	for (i = 5; i < 9; ++i) {
		if (month & mask) {
			*date += (1 << i);
		}
		month >>= 1;
	}
}

void pack_year(int year, short *date)
{
	int i, mask = 1;
	for (i = 9; i < 16; ++i) {
		if (year & mask) {
			*date += (1 << i);
		}
		year >>= 1;
	}
}
