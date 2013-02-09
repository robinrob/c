/* A program which prints the next day of the year
 * given day and month numbers. */

#include "date.h"

int next_date(int date)
{
	int day = 0, month = 0, year = 0, i, mask = 1;
	
	day = unpack_day(date);
	month = unpack_month(date);
	year = unpack_year(date);
	
	day = next_day(day, month);
	month = next_month(day, month);
	if (day == 1 && month == 1) {
		year++;
	}
	
	return pack_date(day, month, year);
}

day next_day(day d, month m)
{
	int next_day;
	if (((int) d) != MONTH_ENDS[m - 1]) {
		next_day = ++d;
	}
	else {
		next_day = (day) ((int) ((d % MONTH_ENDS[m - 1]) + 1));
	}
	return next_day;
}

month next_month(day d, month m)
{
	month next_month = m;
	if (d == 1) {
		next_month = (month) ((int) ((m + 1) % 12));
	}
	return next_month;
}

void print_month(month m)
{
	switch (m) {
		case jan:
			printf("January");
			break;
		case feb:
			printf("February");
			break;
		case mar:
			printf("March");
			break;
		case apr:
			printf("April");
			break;
		case may:
			printf("May");
			break;
		case jun:
			printf("June");
			break;
		case jul:
			printf("July");
			break;
		case aug:
			printf("August");
			break;
		case sep:
			printf("September");
			break;
		case oct:
			printf("October");
			break;
		case nov:
			printf("November");
			break;
		case dec:
			printf("December");
			break;
	}
}

