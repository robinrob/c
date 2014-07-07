#include <stdio.h>

enum day {sun, mon, tue, wed, thu, fri, sat};
typedef enum day day;

day next_day(day d);
day next_day2(day d);

int main(void)
{
	day d;
	printf("Enter an integer 0 to 6: ");
	scanf("%d", &d);
	printf("Next day is: %d\n", next_day(d));
	printf("Or: %d\n", next_day2(d));
	
	return 0;
}

day next_day(day d)
{
	day next_day;
	
	switch(d) {
		case sun:
			next_day = mon;
			break;
		case mon:
			next_day = tue;
			break;
		case tue:
			next_day = wed;
			break;
		case wed:
			next_day = thu;
			break;
		case thu:
			next_day = fri;
			break;
		case fri:
			next_day = sat;
			break;
		case sat:
			next_day = sun;
			break;
	}
	return next_day;
}

day next_day2(day d)
{
	return (day) ((d + 1) % 7);
}
