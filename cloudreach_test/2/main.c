#include <stdio.h>
#include <stdlib.h>

int dist_digits_count (int n);
int cmp(const void *vp, const void *vq);
void wrt_array(int *a, int n);

int main ()
{
	printf("result: %d\n", dist_digits_count(151973428));
	return 0;
}

int dist_digits_count (int n)
{
	int div, digits[10] = {0}, i, cnt, digit;

	div = 1;
	while (n / div) {
		div *= 10;
	}
	div /= 10;

	i = 0;
	while (n > 0) {
		digits[i] = n / div;
		n -= (digits[i] * div);
		div /= 10;
		++i;
	}

	wrt_array(digits, i);
	qsort(digits, i, sizeof(int), cmp);
	wrt_array(digits, i);

	cnt = 0;
	digit = digits[--i];
	while (i >= 0) {
		if (digits[--i] == digit) {
			digit = digits[i];
			continue;
		}
		else {
			++cnt;
		}
		digit = digits[i];
	}

	return cnt;
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
