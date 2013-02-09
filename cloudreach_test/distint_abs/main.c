#include <stdio.h>
#include <stdlib.h>

int nDistinctAbs(int a[], int n);

int main(void)
{
	int a[] = {-10, -7, -7, -6, -2, 0, 4, 4, 5, 8};
	printf("n distinct: %d\n", nDistinctAbs(a, 10));
	return 0;
}

int nDistinctAbs(int a[], int n)
{
	int *rec, max, i, cnt = 0;
	abs(a[n - 1]) > abs(a[0]) ? (max = abs(a[n - 1])) : (max = abs(a[0]));
	rec = calloc(max + 1, sizeof(int));

	for (i = 0; i < n; ++i) {
		if (!rec[abs(a[i])]) {
			rec[abs(a[i])]++;
			++cnt;
		}
	}
	return cnt;
}
