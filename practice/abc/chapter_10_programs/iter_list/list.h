#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct linked_list {
	DATA d;
	struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

/* List creation using iteration. */
LINK s_to_l(char s[]);
/* Count a list recursively. */
int count_it(LINK head);
