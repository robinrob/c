/* Function testing functions. */

#include "dllist.h"

/* Tests list printing functions. */
void test_print(NODE *list)
{
	printf("The list:\n");
	print_list(list);

	printf("In reverse:\n");
	print_list_reverse(list);
}

/* Tests insertion/deletion functions. */
void test_ins_del(NODE *list)
{
	/* Insert elements into the list. */
	DATA d;
	d.name = "INSERTION";
	d.age = 1;
	d.weight = 0;
	list = insert(d, list, 0);
	list = insert(d, list, 4);
	list = insert(d, list, 7);
	printf("With insertions:\n");
	print_list(list);

	/* Delete elements from the list. */
	list = delete(list, 0);
	list = delete(list, 3);
	list = delete(list, 5);
	printf("With deletions:\n");
	print_list(list);
}

/* Tests del_dupl() function. */
void test_del_dupl(NODE *list)
{
	DATA d;
	d.name = "DUPLICATE";
	d.age = 0;
	d.weight = 0;
	list = insert(d, list, 2);
	list = insert(d, list, 4);
	printf("With duplicate values:\n");
	print_list(list);
	list = del_dupl(list);
	printf("Test del_dupl():\n");
	print_list(list);
}
