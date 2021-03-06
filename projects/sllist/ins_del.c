/* Insertion & deletion functions for Singly-Linked Lists. */

#include "sllist.h"

/* Inserts an element into the given list, at the
 * given list position (starting from 0). */
NODE *insert(DATA d, NODE *list, int pos)
{
	NODE *p, *next, *prev;
	assert(pos >= 0);
	assert(list != NULL);

	p = malloc(sizeof(NODE));
	p -> data = d;
	if (pos == 0) {
		next = list;
		list = p;
	}
	else {
		int length = cnt_list(list);
		if (pos > length ) {
			pos = length;
		}
		prev = get_node(list, pos - 1);
		next = prev -> next;
		prev -> next = p;
	}
	p -> next = next;
	return list;
}

/* Deletes an element at the given list position
 * in the given list (starting from 0).
 */
NODE *delete(NODE *list, int pos)
{
	NODE *p, *prev, *next;
	assert(pos >= 0);
	assert(list != NULL);

	if (pos == 0) {
		p = list;
		list = (list) -> next;
	}
	else {
		prev = get_node(list, pos - 1);
		p = prev -> next;
		next = p -> next;
		prev -> next = next;
	}
	free(p);
	return list;
}
