/* Insertion & deletion functions for Doubly-Linked Lists. */

#include "dllist.h"

/* Inserts an element into the given list, at the
 * given list position (starting from 1). */
NODE *insert(DATA d, NODE *list, int pos)
{
	NODE *p, *prev, *next;
	assert(pos >= 0);
	assert(list != NULL);

	p = malloc(sizeof(NODE));
	p -> data = d;
	if (pos == 0) {
		prev = NULL;
		next = list;
		list = p;
	}
	else {
		int length = cnt_list(list);
		if (pos > length) {
			pos = length;
		}
		prev = get_node(list, pos - 1);
		next = prev -> next;
		prev -> next = p;
	}
	p -> next = next;
	p -> prev = prev;

	if (next != NULL) {
		next -> prev = p;
	}
	return list;
}

/* Deletes an element at the given list position
 * in the given list (starting from 1).
 */
NODE *delete(NODE *list, int pos)
{
	NODE *p, *prev, *next;
	assert(pos >= 0);
	assert(list != NULL);

	p = get_node(list, pos);
	assert(p != NULL);
	prev = p -> prev;
	next = p -> next;
	if (pos == 0) {
		list = next;
	}
	else {
		prev -> next = next;
	}
	if (next != NULL) {
		next -> prev = prev;
	}
	free(p);
	return list;
}

