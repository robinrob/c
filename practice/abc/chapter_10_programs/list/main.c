//Self-referential structures

#include <stdio.h>

struct list {
	int data;
	struct list *next;
};

typedef struct list list;



int main(void)
{
	list a, b, c;
	a.next = b.next = c.next = NULL;

	a.data = 1;
	b.data = 2;
	c.data = 3;

	a.next = &b;
	b.next = &c;

	printf("a.next -> data: %d\n", a.next -> data);
	printf("a.next -> next -> data: %d\n", a.next -> next -> data);

	return 0;
}
