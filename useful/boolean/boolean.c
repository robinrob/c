/* Different ways to represent boolean values. */

#include <stdio.h>
#include <stdbool.h> //In C99 standard.

union boolean {
	unsigned val : 1; //Bit-field of size 1.
};

typedef union boolean boolean;

/* Test bit-field boolean value. */
void test_boolean(boolean b);

/* Test C99 bool macro. */
void test_bool(bool b);

int main(void)
{
	boolean b1;
	bool b2;

	b1.val = 1;
	b2 = true;
	test_boolean(b1);
	test_bool(b2);

	b1.val = 0;
	b2 = false;
	test_boolean(b1);
	test_bool(b2);

	return 0;
}

/* Test bit-field boolean value. */
void test_boolean(boolean b)
{
	if (b.val) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
}

/* Test C99 bool macro. */
void test_bool(bool b)
{
	if (b) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
}
