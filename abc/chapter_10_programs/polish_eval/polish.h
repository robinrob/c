/* A linked list implementation of a Polish stack. */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 10000

struct data {
	enum {operator, value} kind;
	union {
		char op;
		int val;
	} u;
};

typedef struct data data;
typedef enum {true, false} boolean;

struct elem {
	data d;
	struct elem *next;
};

typedef struct elem elem;

struct stack {
	int cnt;
	elem *top;
};

typedef struct stack stack;
int evaluate(stack *polish);
void fill(stack *stk, const char *str);
void print_data(data *dp);
void print_stack(stack *stk);
void initialise(stack *stk);
void push(data d, stack *stk);
data pop(stack *stk);
data top(stack *stk);
boolean empty(const stack *stk);
boolean full(const stack *stk);
