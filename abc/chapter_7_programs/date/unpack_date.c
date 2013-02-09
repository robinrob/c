#include "date.h"

void unpack_date(int date)
{
	int day, month, year, i, mask = 1;
	day = unpack_day(date);
	month = unpack_month(date);
	year = unpack_year(date);
	printf("%d/%d/%d", day, month, year);
}

int unpack_day(int date)
{
	int day = 0, i, mask = 1;
	for (i = 0; i < 5; ++i) {
		if (date & mask) {
			day += (1 << i);
		}
		mask <<= 1;
	}
	return day;
}

int unpack_month(int date)
{
	int month = 0, i, mask = (1 << 5);
	for (i = 0; i < 4; ++i) {
		if (date & mask) {
			month += (1 << i);
		}
		mask <<= 1;
	}
	return month;
}

int unpack_year(int date)
{
	int year = 0, i, mask = (1 << 9);
	for (i = 0; i < 7; ++i) {
		if (date & mask) {
			year += (1 << i);
		}
		mask <<= 1;
	}
	return year;
}
