/* A program which prints the next day of the year
 * given day and month numbers. */

#include <stdio.h>
#include <assert.h>

enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
typedef enum month month;
typedef int day;

static int MONTH_ENDS[12] = {31, 28, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31};

day next_day(day d, month m);
month next_month(day d, month m);
void print_month(month m);

int main(void)
{
	int d;
	int m;
	printf("Enter day: ");
	scanf("%d", &d);
	printf("Enter month: ");
	scanf("%d", &m);
	--m;
	assert(d <= MONTH_ENDS[m]);
	d = next_day(d, m);
	m = next_month(d, m);
	printf("Next day: %d ", d);
	print_month(m);
	printf("\n");
	return 0;
}

day next_day(day d, month m)
{
	day next_day;
	if (((int) d) != MONTH_ENDS[m]) {
		next_day = ++d;
	}
	else {
		next_day = (day) ((int) ((d % MONTH_ENDS[m]) + 1));
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

