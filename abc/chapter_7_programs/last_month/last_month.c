#include "last_month.h"

month last_month(month m)
{
	assert((int) m >= 0 && (int) m < 12);
	return (month) (((m - 1) + 12) % 12);
}
