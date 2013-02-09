/* Tree functions. */

#include "tree.h"

//Inorder binary tree traversal.
void inorder(BTREE root)
{
	if (root != NULL) {
		inorder(root -> left); //recur left
		printf("%c ", root -> d);
		inorder(root -> right); //recur right
	}
}

//Preorder binary tree traversal.
void preorder(BTREE root)
{
	if (root != NULL) {
		printf("%c ", root -> d);
		preorder(root -> left); //recur left
		preorder(root -> right); //recur right
	}
}

//Postorder binary tree traversal.
void postorder(BTREE root)
{
	if (root != NULL) {
		postorder(root -> left); //recur left
		postorder(root -> right); //recur right
		printf("%c ", root -> d);
	}
}

//Allocate space for a new node.
BTREE new_node(void)
{
	return (malloc(sizeof(NODE)));
}

//Create and initialise a new btree node.
BTREE init_node(DATA d1, BTREE p1, BTREE p2)
{
	BTREE t;

	t = new_node();
	t -> d = d1;
	t -> left = p1;
	t -> right = p2;
	return t;
}

//Create a new btree.
BTREE create_tree(DATA a[], int i, int size)
{
	if (i >= size)
		return NULL;
	else
		return (init_node(a[i],
				create_tree(a, 2 * i + 1, size),
				create_tree(a, 2 * i + 2, size)));
}
