/* Testing input of a word list. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 50
#define MAXLIST 50

void print_list(char **left, char **right);

int main(void)
{
  char *c[MAXLIST], s[MAXWORD];
  int i, max_el;
  
  printf("Enter some words: ");
  i = 0;
  while ((scanf("%s", s) == 1) && (i < MAXLIST)) {
    if (strcmp(s, "endoflist") == 0) {
      break;
    }
    *(c + i) = calloc(MAXWORD, sizeof(char));
    strcpy(*(c + i), s);
    ++i;
  }
  max_el = i;
  
  printf("List of words:\n");
  print_list(c, c + max_el - 1);
  for (i = 0; i < max_el; ++i) {
    free(*(c + i));
  }
  
  return 0;
}

//Print the list given pointers to the end values.
void print_list(char **left, char **right)
{
  while (left <= right) {
    printf("%s\n", *(left++));
  }
  printf("\n");
}
  