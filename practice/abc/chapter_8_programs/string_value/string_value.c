#include <stdio.h>
#include <ctype.h>

int string_val(char *s);

int main(void)
{
  int i;
  char *c[] = {"hello", "i", "am", "robin"};
  
  for (i = 0; i < 4; ++i) {
    printf("%s: %d\n", *(c + i), string_val(*(c + i)));
  }
  
  return 0;
}

int string_val(char *s)
{
  int i = 0, val = 0;
  while (*(s + i) != '\0') {
    val += tolower(*(s + i)) -'a';
    ++i;
  }
  return val;
}
