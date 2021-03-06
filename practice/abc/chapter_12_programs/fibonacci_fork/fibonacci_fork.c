/* Computes Fibonacci numbers using a child process
 * and prints time asynchronously using the parent process.
 */

#include <stdio.h>
#include <time.h>

int fib(int);
int fork(void);
void sleep(unsigned);

#define N 50

int main(void)
{
	int begin = time(NULL), i;

	if (fork() == 0) {
		for (i = 0; i < N; ++i) {
			printf("fib(%2d) = %d\n", i, fib(i));
		}
	}
	else {
		for (i = 0; i < N; ++i) {
			sleep(2);
			printf("elapsed time = %d\n", ((int) time(NULL) - begin));
		}
	}
	return 0;
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
