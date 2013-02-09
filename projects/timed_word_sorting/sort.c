/* Sorts an array using the bubblesort and mergesort algorithms and
 * compares the execution times.
 */

#include "sort_words.h"

#define MAX_PRINT_LENGTH 10

void do_sort_words(char *w[], int n);
void do_mergesort_words(char *w[], int n);

int main(void)
{
	char word[MAXWORD];
	char *a[N], *b[N];
	int n, i;

	for (i = 0; scanf("%s", word) == 1; ++i) {
		if (i >= N) {
			error_exit_too_many_words();
		}
		if (strlen(word) >= MAXWORD) {
			error_exit_word_too_long();
		}
		a[i] = calloc(strlen(word) + 1, sizeof(char));
		b[i] = calloc(strlen(word) + 1, sizeof(char));
		if (a[i] == NULL) {
			error_exit_calloc_failed();
		}
		strcpy(a[i], word);
		strcpy(b[i], word);
	}
	n = i;
	
	do_sort_words(a, n);
	do_mergesort_words(b, n);
	
	for (i = 0; i < n; ++i) {
		free(a[i]);
		free(b[i]);
	}
	
	return 0;
}

void do_sort_words(char *w[], int n)
{
	printf("\nsort_words:\n");
	start_time();
	sort_words(w, n);
	print_time();
}

void do_mergesort_words(char *w[], int n)
{
	printf("\nmergesort_words:\n");
	start_time();
	mergesort_words(w, n);
	print_time();
}
