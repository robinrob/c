/* sprintf example */
#include <stdio.h>

char *func(void);

int main ()
{
  char buffer [50];
  int n, a=5, b=3;
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  printf("%s\n", func());
  return 0;
}

char *func(void)
{
      char buffer [50];
      int n, a=5, b=3;
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  return buffer;
}
