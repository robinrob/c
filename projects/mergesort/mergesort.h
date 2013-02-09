/*
 * mergeSort.h
 *
 *  Created on: Feb 5, 2010
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void fill_array(int *a, int n);
void wrt_array(int *a, int n);
void bubble_sort(int *a, int n);
void merge(int *a, int *b, int *c, int m, int n);
void swap(int *a, int *b);
void merge_sort(int *a, int n);
int* get_comps(int n);
