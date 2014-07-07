/* Main file for the Towers of Hanoi project. */

#include "hanoi.h"

int cnt = 0;

int main(void)
{
	int n;

	n = get_n_from_user();
	assert(n > 0);
	move(n, 'A', 'B', 'C');
	printf("\nTotal number of moves: %d\n", cnt);
	return 0;
}
