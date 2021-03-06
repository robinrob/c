//Implementation of a double-ended queue ADT.

#include <stdio.h>

#define MAX_LEN 50

//Double-ended queue.
struct deque {
	char q[MAX_LEN];
	int front;
	int rear;
};

typedef struct deque		deque;
typedef	enum {false, true} 	boolean;
typedef	char				data;

void add_to_front(deque *, data);
void add_to_rear(deque *, data);
data take_from_front(deque *);
data take_from_rear(deque *);
boolean empty(deque *);
boolean full(deque *);
void reset(deque *);

int main(void)
{
	deque dq;
	reset(&dq);
	int i;

	char str[] = "My name is Robin Smith!";
	for (i = 0; str[i] != '\0'; ++i) {
		if (!full(&dq)) {
			add_to_rear(&dq, str[i]);
		}
	}
	for (i = 0; str[i] != '\0'; ++i) {
		if (!full(&dq)) {
			add_to_front(&dq, str[i]);
		}
	}

	while (!empty(&dq)) {
		putchar(take_from_rear(&dq));
	}

	return 0;
}

//Add data to front of queue.
void add_to_front(deque *queue, data d)
{
	queue -> front--;
	queue -> q[queue -> front] = d;
}

//Add data to rear of queue.
void add_to_rear(deque *queue, data d)
{
	queue -> q[queue -> rear++] = d;
}

//Take data from front of queue.
data take_from_front(deque *queue)
{
	return queue -> q[queue -> front++];
}

//Take data from rear of queue.
data take_from_rear(deque *queue)
{
	queue -> rear--;
	return queue -> q[queue -> rear];
}

//Check if queue is empty.
boolean empty(deque *queue)
{
	if (queue -> front == queue -> rear)
		return true;
	else
		return false;
}

//Check if queue is full.
boolean full(deque *queue)
{
	if (queue -> rear == (MAX_LEN - 1) || queue -> front < 0)
		return true;
	else
		return false;
}

//Resets the queue.
void reset(deque *queue)
{
	queue -> front = MAX_LEN / 2 - 1;
	queue -> rear = MAX_LEN / 2 - 1;
}
