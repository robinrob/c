/* Displays possible throws to achieve a given darts score. */

#include <stdio.h>

#define TREBLE "treble "
#define DOUBLE "double "
#define SINGLE "single "

void exit(int status);
void score(int multiplier, int dart);
int check_mode(int mode, int multiplier, int dart);
char* strcat(char* a, char* b);

int main(void)
{
	int mode, n, i, j, k, a, b, c, cnt = 0;

	printf("%s\n%s\n%s",
			"Any score (1)",
			"Finishing score (2)",
			"Select mode: ");
	scanf("%d", &mode);
	if (mode > 2) {
		printf("Mode must be '1' or '2'\n");
		exit(0);
	}
	printf("Enter a score: ");
	scanf("%d", &n);

	for (a = 1; a <= 3; ++a)
		for (i = 1; i <= 21 &&
		    (i == 21) ? (i = 25) : 1 &&
		    i <= n; ++i) {
			if ((i * a == n) && check_mode(mode, a, i)) {
				printf("%d = ");
				score(a, i);
				++cnt;
			}
			for (b = 1; b <= 3; ++b)
				for (j = 1; j <= 21 &&
		        (j == 21) ? (j = 25) : 1 &&
				(a * i + j <= n); ++j) {
					if ((i * a + b * j == n) && check_mode(mode, b, j)) {
						printf("%d = %s, %s,\n", n,
								score(a, i),
								score(b, j));
							++cnt;
					}
					for (c = 1; c <= 3; ++c)
						for (k = 1; k <= 21 &&
						(k == 21) ? (k = 25) : 1 &&
						(a * i + b * j + k <= n); ++k) {
							if ((i * a + j * b + k * c == n) && check_mode(mode, c, k)) {
								printf("%d = %s, %s, %s\n", n,
										score(a, i),
										score(b, j),
										score(c, k));
								++cnt;
							}
						}
				}
		}
	printf("total possibilities: %d\n", cnt);

	return 0;
}

void score(int m, int d)
{
	char* multiplier;
	char* score;
	char* d_string;

	if (m == 1)
		multiplier = SINGLE;
	else if (m == 2)
		multiplier = DOUBLE;
	else if (m == 3)
		multiplier = TREBLE;
	else printf("ERROR: multiplier OUT OF RANGE");

	if (d <= 20) {
		printf("%s %d", multiplier, d);
	}
	else if (d == 25 && m == 1)
		printf("25");
	else if (d == 25 && m == 2)
		printf("BULLSEYE!");
	else if (d == 25 && m == 3)
		printf("ERROR: dart OUT OF RANGE");

	return score;
}

int check_mode(int mode, int multiplier, int dart)
{
	if (dart == 25 && multiplier == 3)
		return 0;
	if (mode == 1)
		return 1;
	else if (mode == 2)
		if (multiplier == 2)
			return 1;
		else
			return 0;
	return 0;
}
