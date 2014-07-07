/* Quicksort! Implemented for lists of strings. */

#include "sort.h"

//Some very useful macros
#define order(x, y)				if (strcmp(a, b)) { swap_string(&a, &b); }
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

//Useful enumerator type
typedef enum {yes, no} yes_no;

static yes_no find_pivot(char **left, char **right, char **pivot_ptr, int n_piv);
static yes_no find_pivot_3(char **left, char **right, char **pivot_ptr);
static yes_no find_pivot_5(char **left, char **right, char **pivot_ptr);
static yes_no find_pivot_7(char **left, char **right, char **pivot_ptr);
static char **partition(char **left, char **right, char *pivot);

//The main quicksort function.
void quicksort(char **left, char **right, int n_piv)
{
  char **p, *pivot;

  
  if (find_pivot(left, right, &pivot, n_piv) == yes) {
    p = partition(left, right, pivot);
    quicksort(left, p - 1, n_piv);
    quicksort(p, right, n_piv);
  }
}

static yes_no find_pivot(char **left, char **right, char **pivot_ptr, int n_piv)
{
	if (n_piv == 3) {
		return find_pivot_3(left, right, pivot_ptr);
	}
	else if (n_piv == 5) {
		return find_pivot_5(left, right, pivot_ptr);
	}
	else if (n_piv == 7){
		return find_pivot_7(left, right, pivot_ptr);
	}
	else {
		return find_pivot_3(left, right, pivot_ptr);
	}
}

static yes_no find_pivot_3(char **left, char **right, char **pivot_ptr)
{
  char **p;
  int step = (right - left) / 2;
  char *a = *left;
  char *b = *(left + step);
  char *c = *right;

  o3(a, b, c);

  if (strcmp(a, b) == -1) {
    *pivot_ptr = b;
    return yes;
  }
  if (strcmp(b, c) == -1) {
    *pivot_ptr = c;
    return yes;
  }
  for (p = left + 1; p <= right; ++p) {
    if (strcmp(*p, *left) != 0) {
        *pivot_ptr = (strcmp(*p, *left) == -1) ? *left : *p;
      return yes;
    }
  }
  return no;
}

static yes_no find_pivot_5(char **left, char **right, char **pivot_ptr)
{
  char **p;
  int step = (right - left) / 4;
  char *a = *left;
  char *b = *(left + step);
  char *c = *(left + step + step);
  char *d = *(left + step + step + step);
  char *e = *right;

  o5(a, b, c, d, e);

  if (strcmp(a, b) == -1) {
    *pivot_ptr = b;
    return yes;
  }
  if (strcmp(b, c) == -1) {
    *pivot_ptr = c;
    return yes;
  }
  if (strcmp(c, d) == -1) {
    *pivot_ptr = d;
    return yes;
  }
  if (strcmp(d, e) == -1) {
    *pivot_ptr = e;
    return yes;
  }
  for (p = left + 1; p <= right; ++p) {
    if (strcmp(*p, *left) != 0) {
        *pivot_ptr = (strcmp(*p, *left) == -1) ? *left : *p;
      return yes;
    }
  }
  return no;
}

static yes_no find_pivot_7(char **left, char **right, char **pivot_ptr)
{
  char **p;
  int step = (right - left) / 6;
  char *a = *left;
  char *b = *(left + step);
  char *c = *(left + step + step);
  char *d = *(left + step + step + step);
  char *e = *(left + step + step + step + step);
  char *f = *(left + step + step + step + step);
  char *g = *right;

  o7(a, b, c, d, e, f, g);

  if (strcmp(a, b) == -1) {
    *pivot_ptr = b;
    return yes;
  }
  if (strcmp(b, c) == -1) {
    *pivot_ptr = c;
    return yes;
  }
  if (strcmp(c, d) == -1) {
    *pivot_ptr = d;
    return yes;
  }
  if (strcmp(d, e) == -1) {
    *pivot_ptr = e;
    return yes;
  }
  if (strcmp(e, f) == -1) {
    *pivot_ptr = f;
    return yes;
  }
  if (strcmp(f, g) == -1) {
    *pivot_ptr = g;
    return yes;
  }
  for (p = left + 1; p <= right; ++p) {
    if (strcmp(*p, *left) != 0) {
        *pivot_ptr = (strcmp(*p, *left) == -1) ? *left : *p;
      return yes;
    }
  }
  return no;
}

static char **partition(char **left, char **right, char *pivot)
{
  while (left <= right) {
    while (strcmp(*left, pivot) == -1)
      ++left;
    while (strcmp(*right, pivot) >= 0)
      --right;
    if (left < right) {
      swap_string(left, right);
      ++left;
      --right;
    }
  }
  return left;
}
