#include <stdio.h>
#include <stdlib.h>

void wrt_array(int *a, int n);
int cmp(const void *vp, const void *vq);
int amplitude (int a[], int n);

int main ()
{
	int a[] = {10, 2, 44, 15, 39, 20};
	printf("amp: %d\n", amplitude(a, 6));
	wrt_array(a, 6);

	return 0;
}

int cmp(const void *vp, const void *vq)
{
	const int *p = vp;
	const int *q = vq;
	int diff = *p - *q;
	return ((diff >= 0.0) ? ((diff > 0.0) ? +1 : 0) : -1);
}

void wrt_array(int *a, int n)
{
	int i;

	printf("[");
	for (i = 0; i < n; ++i) {
		printf("%d%s", a[i], ((i < n - 1) ? ", " : "]\n"));
	}
}

int amplitude (int a[], int n)
{
	qsort(a, n, sizeof(int), cmp);
	return abs(a[n - 1] - a[0]);
}
