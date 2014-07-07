/* The basic stack routines. */

#include "stack.h"

//Initialise the stack.
void initialise(stack *stk)
{
	stk -> cnt = 0;
	stk -> top = NULL;
}

//Push data onto stack.
void push(data d, stack *stk)
{
	elem *p;

	p = malloc(sizeof(elem));
	p -> d = d;
	p -> next = stk -> top;
	stk -> top = p;
	stk -> cnt++;
}

//Take data off the stack.
data pop(stack *stk)
{
	data d;
	elem *p;

	d = stk -> top -> d;
	p = stk -> top;
	stk -> top = stk -> top -> next;
	stk -> cnt--;
	free(p);
	return d;
}

//Check the data at the top of the stack.
data top(stack *stk)
{
	return (stk -> top -> d);
}

//Check if the stack is empty.
boolean empty(const stack *stk)
{
	return ((boolean) (stk -> cnt == EMPTY));
}

//Check if the stack is full.
boolean full(const stack *stk)
{
	return ((boolean) (stk -> cnt == FULL));
}
