/* Testing a function to print the next string in
 * a list given a pointer to a string in that list.
 */

#include <stdio.h>

char * next_string(char **s);

int main(void)
{
  char *c[] = {"hello", "i", "am", "robin"};
  
  printf("first string: %s\n", *c);
  printf("next string: %s\n", next_string(c));
  printf("next string: %s\n", next_string(c + 1));
  printf("next string: %s\n", next_string(c + 2));
  
  return 0;
}

char * next_string(char **s)
{
  return *(s + 1);
}
