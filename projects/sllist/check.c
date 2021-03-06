/* Functions that check if things are true or not
 * in Singly-Linked Lists or their elements. */

#include "sllist.h"

/* Checks to see if the two lists are equal. */
boolean check_equal_lists(NODE *list1, NODE *list2)
{
	while (list1 != NULL && list2 != NULL) {
		if (check_equal_data(list1 -> data, list2 -> data)) {
			return false;
		}
		list1 = list1 -> next;
		list2 = list2 -> next;
	}
	return true;
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


