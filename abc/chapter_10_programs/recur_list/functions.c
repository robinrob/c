/* Recursive list functions. */

#include "list.h"

/* List creation using recursion. */
LINK string_to_list(char s[])
{
	LINK head;

	if (s[0] == '\0')
		return NULL;
	else {
		head = malloc(sizeof(ELEMENT));
		head -> d = s[0];
		head -> next = string_to_list(s + 1);
		return head;
	}
}

/* Count a list recursively. */
int count(LINK head)
{
	if (head == NULL)
		return 0;
	else
		return (1 + count(head -> next));
}

/* Print a list recursively. */
void print_list(LINK head)
{
	if (head == NULL)
		printf("NULL");
	else {
		printf("%c --> ", head -> d);
		print_list(head -> next);
	}
}

/* Concatenate list a and b with a as head */
void concatenate(LINK a, LINK b)
{
	assert(a != NULL);
	if (a -> next == NULL)
		a -> next = b;
	else
		concatenate(a -> next, b);
}

/* Inserting an element in a linked list. */
void insert(LINK p1, LINK p2, LINK q)
{
	assert(p1 -> next == p2);
	p1 -> next = q;
	q -> next = p2;
}

/* Recursive deletion of a list. */
void delete_list(LINK head)
{
	if (head != NULL) {
		delete_list(head -> next);
		free(head);
	}
}
