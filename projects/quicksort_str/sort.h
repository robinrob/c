#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

extern char *list[];
extern int N_WORDS;

void quicksort(char **left, char **right, int n_piv);

void swap_string(char **p, char **q);
void print_list(char **left, char **right);
int str_val(char *s);
void print_listvals(char **left, char **right);
void str_o2(char *a, char *b);
void str_o3(char *a, char *b, char *c);

