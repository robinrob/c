/* Testing use of stringization on an already-stringized thing. */

#include <stdio.h>

#define YANK(x) #x

int main(void)
{
	char *s;
	s = "Go home, Yankee!";
	printf("%s\n", s);
	return 0;
}
