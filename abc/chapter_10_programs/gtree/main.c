/* Creating a 9-element general tree. */

#include "gtree.h"

int main(void)
{
	NODE t[9];
	t[0] = *(init_gnode('a', 1, NULL)); //root node
	t[1] = *(init_gnode('b', 2, NULL));
	t[1].sib = init_gnode('f', 6, NULL);
	t[1].sib -> sib = init_gnode('h', 8, NULL);
	t[2] = *(init_gnode('c', 3, NULL));
	t[2].sib = init_gnode('d', 4, NULL);
	t[2].sib -> sib = init_gnode('e', 5, NULL);
//	t[3] = NULL;
//	t[4] = NULL;
//	t[5] = NULL;
	t[6] = *(init_gnode('g', 7, NULL));
//	t[7] = NULL;
//	t[8] = NULL;

	preorder_g(t, 0);

	return 0;
}
