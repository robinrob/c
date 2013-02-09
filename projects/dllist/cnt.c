/* Counting functions for Doubly-Linked Lists. */

#include "dllist.h"

//Counts the length of a list.
int cnt_list(NODE *list)
{
	if (list == NULL) {
		return 0;
	}
	else {
		return cnt_list(list -> next) + 1;
	}
}

