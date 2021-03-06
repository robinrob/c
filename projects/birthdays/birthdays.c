/* Testing the probability of two or more people in a room
 * having the same birthday. */

#include <stdio.h>
#include <time.h>

int main(void)
{
	int birthdays[365], birthday, matched, cunt1 = 0,
		cunt2 = 0, n_people, n_trials;
	register int i, j, k;
	float prob1, prob2;

	for (k = 0; k < 365; ++k)
		birthdays[k] = 0;

	printf("Enter N: ");
	scanf("%d", &n_people);
	printf("Enter number of trials: ");
	scanf("%d", &n_trials);

	srand(time(NULL));
	printf("\nComputing with rand()\n");
	for (i = 0; i < n_trials; ++i) {
		matched = 0;
		for (j = 0; j < n_people; ++j) {
			birthday = rand() % 365 + 1;
			++birthdays[birthday - 1];
			if (birthdays[birthday - 1] > 1)
				matched = 1;
		}
		if (matched)
			++cunt1;
		for (k = 0; k < 365; ++k)
			birthdays[k] = 0;
		if (!(i % (n_trials / 10)))
			printf(".\n");
	}

	printf("\nComputing with lrand48()\n");
	for (i = 0; i < n_trials; ++i) {
		matched = 0;
		for (j = 0; j < n_people; ++j) {
			birthday = lrand48() % 365 + 1;
			++birthdays[birthday - 1];
			if (birthdays[birthday - 1] > 1)
				matched = 1;
		}
		if (matched)
			++cunt2;
		for (k = 0; k < 365; ++k)
			birthdays[k] = 0;
		if (!(i % (n_trials / 10)))
			printf(".\n");
	}

	prob1 = (float) cunt1 / n_trials;
	prob2 = (float) cunt2 / n_trials;
	/*printf("\nrand():\nNumber of trials with two or more birthdays\n"
			"the same: %d\n"
			"Therefore probability of a match = %1.5f\n"
			"Or 1 in %.0lf\n",
			cunt1, prob1, 1.0 / prob1);
	printf("\nlrand48():\nNumber of trials with two or more birthdays\n"
			"the same: %d\n"
			"Therefore probability of a match = %1.5f\n"
			"Or 1 in %.0lf\n",
			cunt2, prob2, 1.0 / prob2);*/
	printf("%-15s%-14s%-12s%-10s\n"
			"%-15s%-14d%-12.5lf%-10.5lf\n"
			"%-15s%-14d%-12.5lf%-10.5lf\n",
			"generator:", "n_matches:", "prob:", "or 1 in:",
			"rand()", cunt1, prob1, 1.0 / prob1,
			"lrand48()", cunt2, prob2, 1.0 / prob2);

	return 0;
}
