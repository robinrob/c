//Testing the stringization # operator in a macro.

#include <stdio.h>

#define GREETINGS(a, b, c) \
		printf(#a ", " #b ", and " #c ": Hello!\n")
		
int main(void)
{
	GREETINGS(Alice, Bob, Carole); /*Alice, Bob, and Carole: Hello!*/
	return 0;
}
