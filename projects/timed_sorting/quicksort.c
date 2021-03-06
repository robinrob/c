/* Quicksort! Pointer version with macros. */

#include "sort.h"

#define swap(x, y)				{ int t; t = x; x = y; y = t; }
#define order(x, y)				if (x > y) swap(x, y)
#define o2(x, y)				order(x, y)
#define o3(x, y, z)				o2(x, y); o2(x, z); o2(y, z)
#define o4(x, y, z, a)			o3(x, y, z); o3(x, y, a); o3(x, z, a); o3(y, z, a)
#define o5(x, y, z, a, b)		o4(x, y, z, a); o4(x, y, z, b); o4(x, y, a, b);\
								o4(x, z, a, b); o4(y, z, a, b)
#define o6(x, y, z, a, b, c)	o5(x, y, z, a, b); o5(x, y, z, a, c); o5(x, y, z, b, c);\
								o5(x, y, a, b, c); o5(x, z, a, b, c); o5(y, z, a, b, c)
#define o7(x, y, z, a, b, c, d)	o6(x, y, z, a, b, c); o6(x, y, z, a, b, d); o6(x, y, z, a, c, d);\
								o6(x, y, z, b, c, d); o6(x, y, a, b, c, d); o6(x, z, a, b, c, d);\
								o6(y, z, a, b, c, d)

typedef enum {yes, no} yes_no;

static yes_no find_pivot(int *left, int *right, int *pivot_ptr, int n_piv);
static yes_no find_pivot_3(int *left, int *right, int *pivot_ptr);
static yes_no find_pivot_5(int *left, int *right, int *pivot_ptr);
static yes_no find_pivot_7(int *left, int *right, int *pivot_ptr);
static int *partition(int *left, int *right, int pivot);

void quicksort(int *left, int *right, int n_piv)
{
	int *p, pivot;

	//printf("*left: %d, *right: %d\n", *left, *right);
	/*if (getchar() != '\n') {
		exit(1);
	}*/

	if (find_pivot(left, right, &pivot, n_piv) == yes) {
		p = partition(left, right, pivot);
		quicksort(left, p - 1, n_piv);
		quicksort(p, right, n_piv);
	}
}

static yes_no find_pivot(int *left, int *right, int *pivot_ptr, int n_piv)
{
	if (n_piv == 3) {
		return find_pivot_3(left, right, pivot_ptr);
	}
	else if (n_piv == 5) {
		return find_pivot_5(left, right, pivot_ptr);
	}
	else {
		return find_pivot_7(left, right, pivot_ptr);
	}
}

static yes_no find_pivot_3(int *left, int *right, int *pivot_ptr)
{
	int a, b, c, step, *p;

	step = (right - left) / 2;
	a = *left;
	b = *(left + step);
	c = *right;

	o3(a, b, c);

	if (a < b) {
		*pivot_ptr = b;
		return yes;
	}
	if (b < c) {
		*pivot_ptr = c;
		return yes;
	}
	for (p = left + 1; p <= right; ++p) {
		if (*p != *left) {
			*pivot_ptr = (*p < *left) ? *left : *p;
			//printf("pivot: %d\n", *pivot_ptr);
			return yes;
		}
	}
	return no;
}

static yes_no find_pivot_5(int *left, int *right, int *pivot_ptr)
{
	int a, b, c, d, e, step, *p;

	step = (right - left) / 4;
	a = *left;
	b = *(left + step);
	c = *(left + step + step);
	d = *(left + step + step + step);
	e = *right;

	o5(a, b, c, d, e);

	if (a < c) {
		*pivot_ptr = c;
		return yes;
	}
	if (c < d) {
		*pivot_ptr = d;
		return yes;
	}
	if (c < e) {
		*pivot_ptr = e;
		return yes;
	}
	for (p = left + 1; p <= right; ++p) {
		if (*p != *left) {
			*pivot_ptr = (*p < *left) ? *left : *p;
			//printf("pivot: %d\n", *pivot_ptr);
			return yes;
		}
	}
	return no;
}

static yes_no find_pivot_7(int *left, int *right, int *pivot_ptr)
{
	int a, b, c, d, e, f, g, step, *p;

	step = (right - left) / 6;
	a = *left;
	b = *(left + step);
	c = *(left + step + step);
	d = *(left + step + step + step);
	e = *(left + step + step + step + step);
	f = *(left + step + step + step + step + step);
	g = *right;

	o7(a, b, c, d, e, f, g);

	if (a < d) {
		*pivot_ptr = d;
		return yes;
	}
	if (d < e) {
		*pivot_ptr = e;
		return yes;
	}
	if (d < f) {
		*pivot_ptr = f;
		return yes;
	}
	if (d < g) {
		*pivot_ptr = g;
		return yes;
	}
	for (p = left + 1; p <= right; ++p) {
		if (*p != *left) {
			*pivot_ptr = (*p < *left) ? *left : *p;
			//printf("pivot: %d\n", *pivot_ptr);
			return yes;
		}
	}
	return no;
}

static int *partition(int *left, int *right, int pivot)
{
	while (left <= right) {
		while (*left < pivot)
			++left;
		//printf("done\n");
		while (*right >= pivot)
			--right;
		if (left < right) {
			swap(*left, *right);
			++left;
			--right;
		}
	}
	return left;
}
