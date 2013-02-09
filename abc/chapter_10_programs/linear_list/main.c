//Linear linked lists.

#include "list.h"

int main(void)
{
	LINK head = malloc(sizeof(ELEMENT));
	head -> d = 'n';
	head -> next = NULL;

	head -> next = malloc(sizeof(ELEMENT));
	head -> next -> d = 'e';
	head -> next -> next = NULL;

	head -> next -> next = malloc(sizeof(ELEMENT));
	head -> next -> next -> d = 'w';
	head -> next -> next -> next = NULL;

	return 0;
}
