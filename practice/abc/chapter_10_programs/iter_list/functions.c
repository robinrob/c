/* Iterative list functions. */

#include "list.h"

/* List creation using iteration. */
LINK s_to_l(char s[])
{
	LINK head = NULL, tail;
	int i;

	if (s[0] != '\0') {
		head = malloc(sizeof(ELEMENT));
		head -> d = s[0];
		tail = head;
		for (i = 1; s[i] != '\0'; ++i) {
			tail -> next = malloc(sizeof(ELEMENT));
			tail = tail -> next;
			tail -> d = s[i];
		}
		tail -> next = NULL;
	}
	return head;
}

/* Count a list recursively. */
int count_it(LINK head)
{
	int cnt = 0;

	for ( ; head != NULL; head = head -> next)
		++cnt;
	return cnt;
}


