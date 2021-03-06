#include <stdio.h>

#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

//New type boolean.
typedef enum boolean {false, true}  boolean;

//Stack contains an array of chars and the index of the top char.
typedef struct stack {
    char s[MAX_LEN];
    int top;
} stack;

void reset(stack *stk);
void push(char c, stack *stk);
char pop(stack *stk);
boolean empty(stack *stk);
boolean full(const stack *stk);
