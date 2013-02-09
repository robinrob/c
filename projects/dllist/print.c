/* Printing functions for Doubly-Linked Lists */

#include "dllist.h"

/* Prints a list of DATA values by following the links. */
void print_list(NODE *list)
{
	print_node_data(list -> prev);
	while(list != NULL) {
		print_node_data(list);
		list = list -> next;
	}
	print_node_data(list);
	putchar('\n');
}

/* Prints a list of DATA values by following the links. */
void print_list_reverse(NODE *list)
{
	while(list -> next != NULL) {
		list = list -> next;
	}
	print_node_data(list -> next);
	while (list != NULL) {
		print_node_data(list);
		list = list -> prev;
	}
	print_node_data(list);
	putchar('\n');
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
