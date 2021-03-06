/* Creation functions for Doubly-Linked Lists. */

#include "dllist.h"

/* Create an array of 5 DATA values. */
DATA *create_array5(void)
{
	DATA *d = calloc(5, sizeof(DATA));
	d[0].name = "Robin",		d[0].age = 23, d[0].weight = 63;
	d[1].name = "Bob Brown",	d[1].age = 36, d[1].weight = 83;
	d[2].name = "Snake Doc",	d[2].age = 39, d[2].weight = 10000;
	d[3].name = "Betty Blue",	d[3].age = 36, d[3].weight = 75;
	d[4].name = "Mac",			d[4].age = 37, d[4].weight = 87;
	return d;
}

/* Creates a DATA list from an array of DATA values
 * and returns a reference to the head of the list. */
NODE *create_list(DATA *array, int n)
{
	int i;
	NODE *p, *list;
	p = malloc(sizeof(NODE));
	list = p;

	p -> prev = NULL;
	for (i = 0; i < n - 1; ++i) {
		NODE *tmp = p;
		p -> data = *(array + i);
		p -> next = malloc(sizeof(NODE));
		p = p -> next;
		p -> prev = tmp;
	}
	p -> data = *(array + n - 1);
	p -> next = NULL;

	return list;
}
