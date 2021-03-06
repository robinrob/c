/* Concatenation functions for Singly-Linked Lists. */

#include "sllist.h"

/* Concatenates list2 onto the end of list1,
 * no matter what!
 */
void concat(NODE *list1, NODE *list2)
{
	while (list1 -> next != NULL) {
		list1 = list1 -> next;
	}
	list1 -> next = list2;
}

/* Iteratively concatenates list2 onto the end of list1
 * ONLY if the two lists are not equal. If
 * they are equal, the head of list1 is returned.
 * If list1 is NULL, list2 is returned.
 */
NODE *concatenate(NODE *list1, NODE *list2)
{
	NODE *head = NULL;

	if (list1 == NULL) {
		return list2;
	}

	if (check_equal_lists(list1, list2) == true) {
		printf("%s\n%s\n",
				"Lists are equal and cycle would result,",
				"Will not concatenate.\n");
		return list1;
	}

	head = list1;
	while (list1 -> next != NULL) {
		list1 = list1 -> next;
	}
	list1 -> next = list2;

	return head;
}

/* Returns a concatenated copy of list1 and list2. */
NODE *copy_cat(NODE *list1, NODE *list2)
{
	NODE *p, *copy, *head = NULL;

	head = copy = malloc(sizeof(NODE));
	while (list1 != NULL) {
		copy -> data = list1 -> data;
		if (list1 -> next != NULL) {
			p = malloc(sizeof(NODE));
			copy -> next = p;
			copy = copy -> next;
		}
		list1 = list1 -> next;
	}
	while (list2 != NULL) {
		p = malloc(sizeof(NODE));
		copy -> next = p;
		copy = copy -> next;
		copy -> data = list2 -> data;
		list2 = list2 -> next;
	}
	copy -> next = NULL;
	return head;
}
