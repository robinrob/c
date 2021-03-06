/* Header file for Doubly-Linked List project. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
	char *name;
	int age;
	int weight;
} DATA;

struct NODE {
	DATA data;
	struct NODE *prev;
	struct NODE *next;
};

/* Ease-of-use typedef */
typedef struct NODE NODE;

/* Boolean values */
typedef enum {true, false} boolean;

/* Prints a list of DATA values by following the links. */
void print_list(NODE *list);

void print_list_reverse(NODE *list);

/* Prints the data stored in the given node. */
void print_node_data(NODE *n);

/* Create an array of 5 DATA values. */
DATA *create_array5(void);

/* Creates a DATA list from an array of DATA values
 * and returns a LINK to the head of the list.
 */
NODE *create_list(DATA *array, int n);

/* Inserts an element into the given list, at the
 * given list position (starting from 1).
 */
NODE *insert(DATA d, NODE *list, int pos);

/* Deletes an element at the given list position
 * in the given list (starting from 1).
 */
NODE *delete(NODE *list, int pos);

/* Returns a pointer to the NODE at the given list
 * position in the given list.
 */
NODE *get_node(NODE *list, int pos);

/* Deletes duplicate-valued elements in the list. */
NODE *del_dupl(NODE *list);

//Counts the length of a list.
int cnt_list(NODE *list);

/* Checks to see whether a list is a cycle. */
boolean check_cycle(NODE *list);

/* Checks to see if two DATA structures are equal or not. */
boolean check_equal_data(DATA d1, DATA d2);

/* Tests list printing functions. */
void test_print(NODE *list);

/* Tests insertion/deletion functions. */
void test_ins_del(NODE *list);

/* Tests del_dupl() function. */
void test_del_dupl(NODE *list);



