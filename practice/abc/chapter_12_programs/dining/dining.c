/* The dining philosopher program.
 *
 * Note: In computer science, a semaphore is a variable
 * or abstract data type that provides a simple but useful
 * abstraction for controlling access by multiple processes
 * to a common resource in a parallel programming environment
 * (wikipedia.org).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5				//Number of philosophers
#define Busy_Eating 1
#define Busy_Thinking 1
#define Left(p) (p) 			//Chopstick macros
#define Right(p) (((p) + 1) % N)

typedef int* semaphore;

semaphore chopstick[N]; //global array


/* Acquite chopsticks, input is philosopher number. */
void pick_up(int me);

/* Relinquish chopsticks, input is philosopher number. */
void put_down(int me);

/* Philosopher process, input is philosopher number. */
void philosopher(int me);

semaphore make_semaphore(void);
void wait(semaphore s);
void signal(semaphore s);

int fork(void);
int pipe(int pd[2]);
int read(int fd, void *buf, unsigned len);
void sleep(unsigned seconds);
int write(int fd, void *buf, unsigned len);

int main(void)
{
	int i;

	for (i = 0; i < N; ++i) { //put chopsticks on the table
		chopstick[i] = make_semaphore();
		signal(chopstick[i]);
	}
	for (i = 0; i < N - 1; ++i) { //create philosophers
		if (fork() == 0) {
			break;
		}
	}
	philosopher(i); //all executing concurrently
	return 0;
}

/* Acquite chopsticks, input is philosopher number. */
void pick_up(int me)
{
	if (me == 0) {
		wait(chopstick[Right(me)]);
		printf("Philosopher %d picks up right chopstick\n", me);
		sleep(1); //simulate slow pick-up encouraging deadlock
		wait(chopstick[Left(me)]);
		printf("Philosopher %d picks up left chopstick\n", me);
	}
	else {
		wait(chopstick[Left(me)]);
		printf("Philosopher %d picks up left chopstick\n", me);
		sleep(1); //simulate slow pick-up encouraging deadlock
		wait(chopstick[Right(me)]);
		printf("Philosopher %d picks up right chopstick\n", me);
	}
}

/* Relinquish chopsticks, input is philosopher number. */
void put_down(int me)
{
	signal(chopstick[Left(me)]);
	signal(chopstick[Right(me)]);
}

/* Philosopher process, input is philosopher number. */
void philosopher(int me)
{
	char *s;
	int i = 1;

	for ( ; ; ++i) { //forever
		pick_up(me);
		s = i == 1 ? "st" : i == 2 ? "nd" : i == 3 ? "rd" : "th";
		printf("	Philosopher %d *EATING* for the %d%s time\n",
				me, i, s);
		sleep(Busy_Eating);
		put_down(me);
		printf("Philosopher %d is thinking\n", me);
		sleep(Busy_Thinking);
	}
}

semaphore make_semaphore(void)
{
	int *sema;

	sema = calloc(2, sizeof(int)); //permanent storage
	pipe(sema);
	return sema;
}

void wait(semaphore s)
{
	int junk;

	if (read(s[0], &junk, 1) <= 0) {
		printf("ERROR: wait() failed, check semaphore creation.\n");
		exit(1);
	}
}

void signal(semaphore s)
{
	if (write(s[1], "x", 1) <= 0) {
		printf("ERROR: write() failed, check semaphore creation.\n");
		exit(1);
	}
}
