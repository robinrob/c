/* Main function for Doubly-Linked List project. */

#include "dllist.h"

int main(void)
{
	DATA *d = create_array5();
	NODE *list = create_list(d, 5);

	test_print(list);
	test_ins_del(list);
	test_del_dupl(list);

	return 0;
}
