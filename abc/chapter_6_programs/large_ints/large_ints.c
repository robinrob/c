/* A program to add large integers together showing a way to represent them. */

#include <assert.h>
#include <stdio.h>

#define N 20

typedef const char cchr;

void add(int sum[], int a[], int b[]);
void multiply(int product[], int a[], int b[]);
void wrt(cchr *s, int a[]);

int main(void)
{
	int a[N] = {4, 6, 3, 2, 5, 0, 9};
	int b[N] = {7, 7, 5, 3, 1, 2, 8, 1, 2, 3};
	int sum[N], product[N];
	int ndigits;
	
	add(sum, a, b);
	wrt("Integer a: ", a);
	wrt("Integer b: ", b);
	wrt("      Sum: ", sum);
	
	multiply(product, a, b);
	wrt("  Product: ", product);
	
	return 0;
}

void add(int sum[], int a[], int b[])
{
	int carry = 0;
	int i;
	
	for (i = 0; i < N; ++i) {
		sum[i] = a[i] + b[i] + carry;
		if (sum[i] < 10) {
			carry = 0;
		}
		else {
			carry = sum[i] / 10;
			sum[i] %= 10;
		}
	}
}

void multiply(int product[], int a[], int b[])
{
	int carry = 0;
	int i, j;
	int sum;
	
	for (i = 0; i < N; ++i) {
		product[i] = 0;
	}
	
	for (i = 0; i < N; ++i) {
		carry = 0;
		for (j = 0; j < N; ++j) {
			product[i + j] += carry;
			product[i + j] += a[i] * b[j];
			if (product[i + j] < 10) {
				carry = 0;
			}
			else {
				carry = product[i + j] / 10;
				product[i + j] %= 10;
			}
		}
	}
}

void wrt(cchr *s, int a[])
{
	int i;
	
	printf("%s", s);
	
	//Print leading zeros as blanks
	for (i = N - 1; i > 0 && a[i] == 0; --i) {
		putchar(' ');
	}
	
	//After a leading digit greater than zero is found,
	//print all the remaining digits, including zeros.
	for ( ; i >= 0; --i) {
		printf("%d", a[i]);
	}
	putchar('\n');
}
