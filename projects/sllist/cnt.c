/* Counting functions for Singly-Linked Lists. */

#include "sllist.h"

/* Counts the length of a list recursively. */
int cnt_list(NODE *list)
{
	if (list == NULL) {
		return 0;
	}
	else {
		return cnt_list(list -> next) + 1;
	}
}

/* Counts the length of a list iteratively. */
int cnt_list_it(NODE *list)
{
	int cnt = 0;

	while (list != NULL) {
		list = list -> next;
		++cnt;
	}
	return cnt;
}
