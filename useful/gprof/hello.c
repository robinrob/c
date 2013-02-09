/* Program for testing use of gprof utility. */

#include <stdio.h>

void print_hello(void);
void print_hello_n(int n);

int main(void)
{
    int n = 0;
    printf("Enter no. calls: ");
    scanf("%d", &n);
    print_hello_n(n);
    return 0;
}

void print_hello(void)
{
    printf("Hello World!\n");
}

void print_hello_n(int n)
{
    for( ; n > 0; --n) {
	print_hello();
    }
}
