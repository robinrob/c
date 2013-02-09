/* Implementation of a general tree. */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct node {
	int child_no;
	DATA d;
	struct node *sib;
};

typedef struct {
	int out;
	int in;
} PAIR;

typedef struct node NODE;
typedef NODE *GTREE;

GTREE new_gnode(void);
GTREE init_gnode(DATA d1, int num, GTREE sibs);
void preorder_g(GTREE t, int ind);

