#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void fill_array(int *a, int n);
void wrt_array(int *a, int n);
void swap(int *a, int *b);
int* get_comps(int n);
void bubblesort(int *a, int n);
void merge(int *a, int *b, int *c, int m, int n);
void mergesort(int *a, int n);
void quicksort (int *left, int *right, int n_piv);
int cmp(const void *vp, const void *vq);
