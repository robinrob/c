/* Using ! operator on a char to see what happens. */

#include <stdio.h>

int main(void)
{

char c = 'A';
int i = 5, j = 10;

printf("%d %d %d\n", !c, !!c, !!!c);
//0, 1, 0
printf("%d %d %d\n", - ! i, ! - i, ! - i - ! j);
//0, 0, 0
printf("%d %d %d\n", ! (6 * j + i - c), ! i-5, ! j - 10);
//1, -5, -10

return 0;
}
