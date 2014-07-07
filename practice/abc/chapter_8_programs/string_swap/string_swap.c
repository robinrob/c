/*Demonstrates swapping two strings in a list of words.*/

#include <stdio.h>

void swap_string(char **p, char **q);
void print_list(char **a, int n);

int main(void)
{
  int n = 4;
  char *a[] = {"hello", "i", "am", "robin", ""};
  printf("List before swap:\n");
  print_list(a, n);
  swap_string(a + 1, a + 2);
  printf("List after swap:\n");
  print_list(a, n);
  
  return 0;
}

void swap_string(char **p, char **q)
{
  char *c = *p;
  *p = *q;
  *q = c;
}

void print_list(char **a, int n)
{
  int i;
  for (i = 0; i < n; ++i) {
    printf("%s\n", *(a + i));
  }
}
