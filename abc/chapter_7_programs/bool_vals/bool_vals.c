#include <stdio.h>

void set_b(int n, int val, char *num);
int b_val(int n, char b);
int fct1(char bool);
int fct2(char bool);
int majority(char bool);

int main(void)
{
	char b = 0;
	int cnt = 0, i, j, k, l, m;
	
	printf("\n%5s%5s%5s%5s%5s%5s%7s%7s%11s\n\n",
			"Cnt", "b1", "b2", "b3", "b4", "b5",
			"fct1", "fct2", "majority");
	
	for (i = 0; i <= 1; ++i) {
		set_b(1, i, &b);
			for (j = 0; j <= 1; ++j) {
				set_b(2, j, &b);
					for (k = 0; k <= 1; ++k) {
						set_b(3, k, &b);
							for (l = 0; l <= 1; ++l) {
								set_b(4, l, &b);
									for (m = 0; m <= 1; ++m) {
										set_b(5, m, &b);
										printf("%5d%5d%5d%5d%5d%5d%6d%7d%9d\n",
								 		 		 ++cnt, b_val(1, b), b_val(2, b), b_val(3, b), b_val(4, b), b_val(5, b),
								   				 fct1(b), fct2(b), majority(b));
									}
							}
					}
			}
	}
	putchar('\n');
	return 0;					
}

void set_b(int n, int val, char *bool)
{
	char mask = (1 << (n - 1));
	if (val && !(*bool & mask)) {
		*bool += mask;
	}
	else if (!val && (*bool & mask)) {
		*bool -= mask;
	}
}

int b_val(int n, char b)
{
	return (b & (1 << (n - 1))) ? 1 : 0;
}

int fct1(char bool)
{
	char mask;
	return (bool & (mask = 1) || bool & (mask <<= 2) || bool & (mask <<= 2));
}

int fct2(char bool)
{
	char mask;
	return ((bool & (mask = 1)) && (bool & (mask <<= 1)) || (bool && (mask <<= 2)) && (bool & (mask <<= 1)));
}

int majority(char bool)
{
	char mask;
	int i, sum = 0;
	for (i = 0; i < 5; ++i) {
		sum += (bool & (mask <<= i));
	}
	return (sum >= 3 ? 1 : 0);
}
