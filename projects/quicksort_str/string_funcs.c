#include "sort.h"

void swap_string(char **p, char **q)
{
  char *c = *p;
  *p = *q;
  *q = c;
}

void print_list(char **left, char **right)
{
  while (left <= right) {
    printf("%s\n", *(left++));
  }
  printf("\n");
}

void print_listvals(char **left, char **right)
{
  while (left <= right) {
    printf("%s: %d\n", *(left), str_val(*left));
    left++;
  }
  printf("\n");
}

int str_val(char *s)
{
  int i = 0, val = 0;
  while (*(s + i) != '\0') {
    val += tolower(*(s + i)) -'a';
    ++i;
  }
  return val;
}
