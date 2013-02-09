#include "last_month.h"

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
