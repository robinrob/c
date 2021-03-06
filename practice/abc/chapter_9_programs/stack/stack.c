/* An implementation of type stack. */

#include "stack.h"

//Resets the stack.
void reset(stack *stk)
{
    stk -> top = EMPTY;
}

//Pushes a char onto the stack.
void push(char c, stack *stk)
{
    stk -> top++;
    stk -> s[stk -> top] = c;
}

//Gets the top char off the stack.
char pop(stack *stk)
{
    return (stk -> s[stk -> top--]);
}

//Returns the value of the top char on the stack.
char top(const stack *stk)
{
    return (stk -> s[stk -> top]);
}

//Checks if the stack is empty.
boolean empty(stack *stk)
{
    return ((boolean) (stk -> top == EMPTY));
}

//Checks if the stack is full.
boolean full(const stack *stk)
{
    return ((boolean) (stk -> top == FULL));
}

