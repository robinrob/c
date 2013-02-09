/* Miscellaneous functions for Doubly-Linked Lists. */

#include "dllist.h"

/* Returns a pointer to the NODE at the given list
 * position in the given list. */
NODE *get_node(NODE *list, int pos)
{
	int i;
	assert(pos >= 0);

	i = 0;
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
