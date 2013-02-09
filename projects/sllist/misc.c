/* Miscellaneous functions for Singly-Linked Lists. */

#include "sllist.h"

/* Turns a cycling list into a straight & finite list. */
void decycle(NODE *list)
{
	int head_ad = (int) list;
	while (list -> next != NULL) {
		if ((int) (list -> next) == head_ad) {
			list -> next = NULL;
			break;
		}
		list = list -> next;
	}
}

/* Returns a pointer to the NODE at the given list
 * position in the given list (starting from 0). */
NODE *get_node(NODE *list, int pos)
{
	int i = 0;
	assert(pos >= 0);

	while (i < pos) {
		if (list == NULL) {
			return list;
		}
		list = list -> next;
		++i;
	}
	return list;
}

/* Deletes duplicate-valued elements in the list. */
NODE *del_dupl(NODE *list)
{
	int i;
	NODE *p, *q;
	p = q = list;

	i = 0;
	while (q != NULL) {
		while (p != NULL) {
			if (p == q) {
				//do nothing
			}
			else if (check_equal_data(p -> data, q -> data) == true) {
				list = delete(list, i);
				p = get_node(list, 0);
				continue;
			}
			p = p -> next;
			++i;
		}
		p = list;
		q = q -> next;
		i = 0;
	}
	return list;
}



