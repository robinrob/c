/* Using fork() to create a child process. */

#include <stdio.h>

int main(void)
{
	int fork(void), value;

	value = fork();
	printf("In main: value = %d\n", value);
	value = fork();
	printf("In main: value = %d\n", value);

	return 0;
}
