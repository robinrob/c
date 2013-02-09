#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int arrLeader (int a[], int n);
int cmp(const void *vp, const void *vq);
void wrt_array(int *a, int n);

int main ()
{
	int *a, i, n = rand() % MAX_N;
	a = calloc(n, sizeof(int));
	for (i = 0; i < n; ++i) {
		if (i < n / 2) {
			a[i] = 5;
		}
		else {
			a[i] = rand() % 5;
		}
	}
	printf("result: %d\n", arrLeader(a, n));
	return 0;
}

int arrLeader (int a[], int n)
{
	int i, cnt = 1;

	//wrt_array(a, n);
	qsort(a, n, sizeof(int), cmp);
	//wrt_array(a, n);

	for (i = 0; i < n - 1; ++i) {
		if (a[i + 1] == a[i]) {
			++cnt;
			if (cnt > n / 2) {
				return a[i];
			}
		}
		else {
			cnt = 1;
		}
	}
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
