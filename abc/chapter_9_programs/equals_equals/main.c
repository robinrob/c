//Test to see what happens when you put two structures into an '==' expression.

typedef struct {
	int val;
} some_struct;

int main(void)
{
	some_struct a, b;
	a.val = 1, b.val = 2;

	a == b;

	return 0;
}
