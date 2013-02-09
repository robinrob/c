/* General-tree functions. */

#include "gtree.h"

//Allocate space for a new node.
GTREE new_gnode(void)
{
	return (malloc(sizeof(NODE)));
}

//Create and initialise a new gtree node.
GTREE init_gnode(DATA d1, int num, GTREE sibs)
{
	GTREE tmp;

	tmp = new_gnode();
	tmp -> d = d1;
	tmp -> child_no = num;
	tmp -> sib = sibs;
	return tmp;
}

//Preorder traversal of general trees.
void preorder_g(GTREE t, int ind)
{
	GTREE tmp; //tmp traverses the sibling list.

	tmp = t + ind; //t[ind] is the root node.
	while (tmp != NULL) {
		printf("%c  %d\n", tmp -> d, tmp -> child_no);
		preorder_g(t, tmp -> child_no);
		tmp = tmp -> sib;
	}
}

//Function buildtree creates a tree from an array of edges.
void buildtree(PAIR edges[], DATA d[], int n, GTREE t[])
{
	int i;
	int x, y; //Points of edge.

	//t[0] takes node 1 as root.
	t[0] = init_gnode(d[1], 1, NULL);
	for (i = 1; i <= n; ++i)
		t[i] = NULL;
	for (i = 0; i < n - 1; ++i) {
		x = edges[i].out;
		y = edges[i].in;
		t[x] = init_gnode(d[y], y, t[x]);
	}
}
