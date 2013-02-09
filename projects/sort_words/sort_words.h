/* Header file for the project
 * sortAlphabetically.h
 *
 *  Created on: Feb 10, 2010
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 50
#define N 300

void error_exit_calloc_failed(void);
void error_exit_too_many_words(void);
void error_exit_word_too_long(void);
void sort_words(char *w[], int n);
void mergesort_words(char *w[], int n);
void merge(char *a[N], int a0, int n, char *b[N], int b0, int m, char *c[N], int c0);
void swap(char **p, char **q);
void wrt_words(char *w[], int n);
int str_comp(char *a, char *b, int n);
int *get_comps(int in);
