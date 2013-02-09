/* Creating a linked list from an array. */

#include "sllist.h"

int main(void)
{
	DATA *d = create_array5();
	NODE *list = create_list(d, 5);

//	test_print(list);
//	test_sort(list);
//	test_cycle(list);
//	test_concatenate(list);
//	test_ins_del(list);
//	test_copy_cat(list);
//	list = copy_cat(list, create_list(d, 5));
	test_print(list);
//	test_del_dupl(list);

	free(list);

	return 0;
}






