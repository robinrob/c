#include "last_month.h"

int main(void)
{
	int m;
	printf("Enter month (1 - 12): ");
	scanf("%d", &m);
	m--;
	printf("Last month: ");
	print_month(last_month((month) m));
	printf("\n");
	return 0;
}
