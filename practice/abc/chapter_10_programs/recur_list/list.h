#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char DATA;

struct linked_list {
	DATA d;
	struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

/* List creation using recursion. */
LINK string_to_list(char s[]);
/* Count a list recursively. */
int count(LINK head);
/* Print a list recursively. */
void print_list(LINK head);
/* Concatenate list a and b with a as head */
void concatenate(LINK a, LINK b);
