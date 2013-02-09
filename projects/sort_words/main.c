/* Sort words alphabetically mate
 * main.c
 *
 *  Created on: Feb 10, 2010
 *      Author: user
 */

#include "sort_words.h"

int main(void)
{
	char word[MAXWORD];
	char *a[N];
	int n, i;

	for (i = 0; scanf("%s", word) == 1; ++i) {
		if (i >= N) {
			error_exit_too_many_words();
		}
		if (strlen(word) >= MAXWORD) {
			error_exit_word_too_long();
		}
		a[i] = calloc(strlen(word) + 1, sizeof(char));
		if (a[i] == NULL) {
			error_exit_calloc_failed();
		}
		strcpy(a[i], word);
	}
	n = i;
	//sort_words(w, n);
	mergesort_words(a, n);
	
	return 0;
}
