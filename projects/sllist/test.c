/* Function testing functions. */

#include "sllist.h"

/* Tests list printing functions. */
void test_print(NODE *list)
{
	/* Print the list using normal version. */
	printf("The list:\n");
	print_list(list);

	/* Test print_list_reverse. */
	printf("The list reversed:\n");
	print_list_reverse(list);

	/* Print list using iterative version */
//	printf("\nThe list printed iteratively:\n");
//	print_list_it(list);
}

/* Tests sorting function. */
void test_sort(NODE *list)
{
	/* Sort DATA list by age & print it */
		printf("Sorted by age:\n");
		bubb_sort_list(list, age, compare);
		print_list(list);

		/* Sort DATA list by name & print it */
		printf("Sorted by name:\n");
		bubb_sort_list(list, name, compare);
		print_list(list);

		/* Sort DATA list by weight & print it */
		printf("Sorted by weight:\n");
		bubb_sort_list(list, weight, compare);
		print_list(list);
}

/* Tests cycle-checking and decycling functions. */
void test_cycle(NODE *list)
{
	/* Check list is a cycle */
	printf("Is list a cycle? %s\n", check_cycle(list) ? "NO" : "YES");

	/* Turn list into a cycle using concat()
	 * & check if it's a cycle. */
	concat(list, list);
	printf("Is list a cycle? %s\n", check_cycle(list) ? "NO" : "YES");

	/* De-cycle the list & check if it's a cycle. */
	decycle(list);
	printf("Is list a cycle? %s\n", check_cycle(list) ? "NO" : "YES");
}

/* Tests concatenation functions. */
void test_concatenate(NODE *list)
{
	/* Use concatenate() to try to turn list into
	 * a cycle. */
	list = concatenate(list, list);

	NODE *el = malloc(sizeof(NODE));
	el -> data.name = "Spiderman";
	el -> data.age = 99;
	el -> data.weight = 0;
	el -> next = NULL;

	/* Use concatenate() to add new element to list. */
	list = concatenate(list, el);
	printf("Concatenated with new element:\n");
	print_list(list);
}

/* Tests copy_cat function. */
void test_copy_cat(NODE *list)
{
	/* Use copy_cat to create a copy of list
	 * concatenated with itself, & print it.
	 */
	NODE *list2 = create_list(create_array5(), 5);
	list = copy_cat(list, list2);
	printf("\nConcatenated copy of list with list:\n");
	print_list(list);
}

/* Tests insertion/deletion functions. */
void test_ins_del(NODE *list)
{
	/* Insert an item into the list & print the list. */
	DATA new;
	new.name = "INSERTION";
	new.age = 1;
	new.weight = 0;
	list = insert(new, list, 0);
	list = insert(new, list, 4);
	list = insert(new, list, 7);
	printf("With insertions:\n");
	print_list(list);

	/* Delete an item from the list & print the list. */
	list = delete(list, 0);
	list = delete(list, 3);
	list = delete(list, 5);
	printf("With deletions:\n");
	print_list(list);
}

/* Tests del_dupl() function. */
void test_del_dupl(NODE *list)
{
	list = del_dupl(list);
	printf("Test del_dupl():\n");
	print_list(list);
}
