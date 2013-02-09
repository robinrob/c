/* Printing methods for Singly-Linked Lists. */

#include "sllist.h"

/* Prints a list of DATA values by following the links. */
void print_list(NODE *list)
{
	while(list != NULL) {
		print_node_data(list);
		list = list -> next;
	}
	if (list == NULL) {
		printf("list NODE:  NULL\n");
	}
	else {
		printf("--MISSING NULL!--\n");
	}
	putchar('\n');
}

/* Prints a list of DATA values using iteration. */
void print_list_it(NODE *list)
{
	int i, n = cnt_list(list);

	for (i = 0; i < n; ++i) {
		print_node_data(list);
		list = list -> next;
	}
	putchar('\n');
}

/* Recursively prints a list in reverse. */
void print_list_reverse(NODE *list)
{
	if (list == NULL) {
		print_node_data(list);
		return;
	}
	else {
		print_list_reverse(list -> next);
		print_node_data(list);
	}
}

/* Prints the data stored in the given node. */
void print_node_data(NODE *n)
{
	if (n == NULL) {
		printf("list NODE:  NULL\n");
	}
	else if (n != NULL) {
		printf("list NODE:  %s%10s%s%3d%s%5d\n",
								"name: ", n -> data.name,
								", age: ", n -> data.age,
								", weight: ", n -> data.weight);
	}
	else {
		printf("--MISSING NULL!--\n");
	}
}
