/* Reads in a set of scores, sorts them and prints them out in order. */

#include <stdio.h>

#define CLASS_SIZE 5

int main(void)
{
	int i, j, score[CLASS_SIZE], sum = 0, temp;

	printf("Input %d scores: ", CLASS_SIZE);
	//Get the scores from the user.
	for (i = 0; i < CLASS_SIZE; ++i) {
		scanf("%d", &score[i]);
		sum += score[i];
	}

	//Sort the scores using a bubble sort.
	for (i = 0; i < CLASS_SIZE - 1; ++i) {
		for (j = CLASS_SIZE - 1; j > i; --j) {
			if (score[j-1] < score[j]) {
				temp = score[j-1];
				score[j-1] = score[j];
				score[j] = temp;
			}
		}
	}
	
	printf("\nOrdered scores:\n\n");
	//Display the scores.
	for (i = 0; i < CLASS_SIZE; ++i)
		printf("   score[%d] = %5d\n", i, score[i]);

	printf("\n%18d%s\n%18.1f%s\n\n",
			sum, " is the sum of all the scores",
			(double) sum / CLASS_SIZE, " is the class average");
	return 0;
}

