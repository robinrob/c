/* Checking functions for Doubly-Linked Lists. */

#include "dllist.h"

/* Checks to see whether a list is a cycle. */
boolean check_cycle(NODE *list)
{
	int head_ad = (int) list;
	while (list -> next != NULL) {
		list = list -> next;
		if (((int) list) == head_ad) {
			return true;
		}
	}
	return false;
}

/* Checks to see if two DATA structures are equal or not. */
boolean check_equal_data(DATA d1, DATA d2)
{
	if (d1.name == d2.name &&
		d1.age == d2.age &&
		d1.weight == d2.weight) {
		return true;
	}
	return false;
}

