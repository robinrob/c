#include "date.h"

int main(void)
{
	int day, month, year, date;
	printf("Enter a day: ");
	scanf("%d", &day);
	printf("Enter a month: ");
	scanf("%d", &month);
	printf("Enter a year (yy): ");
	scanf("%d", &year);
	date = pack_date(day, month, year);
	printf("\nPacked date: ");
	bit_print(date);
	printf("\n");
	printf("Integer date: %d\n", date);
	printf("Unpacked date: ");
	unpack_date(date);
	printf("\n");
	
	printf("\nNext packed date: ");
	date = next_date(date);
	bit_print(date);
	printf("\n");
	printf("Integer date: %d\n", date);
	printf("Unpacked date: ");
	unpack_date(date);
	printf("\n");
	return 0;
}
