#include <stdio.h>

//void function(int n, int *cnt);

int main(void)
{
  int n = 10, cnt = 0;
  function(n, &cnt);
  printf("cnt: %d\n", cnt);
  return 0;
}

function(int n, int *cnt)
{
  ++(*cnt);
  while (*cnt < n) {
    function(n, cnt);
  }
}
