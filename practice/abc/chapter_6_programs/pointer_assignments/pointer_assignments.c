/* Some legal/non-legal assignments involving pointer expressions.
 * pointer_assignments.c */

int main(void)
{
	int i, j, *p, *q;
	p = &i;
	p = &*&i;
	i = (int) p;
	q = &p; //not legal
	*q = &j; //not legal
	i = (*&)j; //not legal
	i = *p++ + *q;

	return 0;
}
