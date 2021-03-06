/* Using a signal handler to catch a control-c. */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define MAXSTRING 100

/* Handles a control-c interrupt signal. */
void cntrl_c_handler(int sig);
/* Computes Fibonacci numbers recursively. */
int fib(int n);

int main(void)
{
	int i;

	signal(SIGINT, cntrl_c_handler);
	for (i = 0; i < 46; ++i) {
		printf("fib(%2d) = %d\n", i, fib(i));
	}
	return 0;
}

void cntrl_c_handler(int sig)
{
	char answer[MAXSTRING];

	printf("\n\n%s%d\n\n%s",
			"Interrup received!  Signal = ", sig,
			"Do you wish to continue or quit? [c/q]: ");
	scanf("%s", answer);
	if (*answer == 'c') {
		signal(SIGINT, cntrl_c_handler);
	}
	else {
		exit(1);
	}
}

/* Computes Fibonacci numbers recursively. */
int fib(int n)
{
	if (n <= 1) {
		return n;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}
