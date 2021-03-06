/* Functions used in sorting a Singly-Linked List. */

#include "sllist.h"

/* Bubble-sorts a list of DATA values using the
 * specified sorting key.
 */
void bubb_sort_list(NODE *list, sort_key key, void comp_func(NODE *, sort_key))
{
	int i, n = cnt_list(list);
	NODE *p;

	for (i = 0; i < n; ++i) {
		p = list;
		while (p -> next != NULL) {
			comp_func(p, key);
			p = p -> next;
		}
	}
}

/* Compares the data stored in the given node
 * and the next one using the specified key value.
 * The data values are swapped if they are out of order.
 */
void compare(NODE *n, sort_key key)
{
	int diff = 0;
	switch(key)
	{
	case age:
		diff = n -> data.age - n -> next -> data.age;
		break;
	case name:
		diff = strcmp(n -> data.name, n -> next -> data.name);
		break;
	case weight:
		diff = n -> data.weight - n -> next -> data.weight;
		break;
	default:
		printf("Programmer error!\n");
		break;
	}
	if (diff > 0) {
		swap(n, n -> next);
	}
}

/* Swaps the data values of two nodes. */
void swap(NODE *n1, NODE *n2)
{
	DATA tmp = n1 -> data;
	n1 -> data = n2 -> data;
	n2 -> data = tmp;
}
