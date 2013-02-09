/* Program to test sorting a list of words using the quicksort algorithm. */

#include "sort.h"

#define MAXLIST 200
#define MAXWORD 20

//Main function.
int main(int argc, char *argv[])
{
	char *a[MAXLIST], s[MAXWORD];
	int i, max_el, n_piv;

	/* Setting number of pivots - if no command-line
	 * parameter is given, n_piv is 3 by default.
	 */
	n_piv = (argc == 2) ? (*(argv[1]) - '0') : 3;

	i = 0;
	while ((scanf("%s", s) == 1) && (i < MAXLIST)) {
		if (strcmp(s, "endoflist") == 0) {
			break;
		}
		*(a + i) = calloc(MAXWORD, sizeof(char));
		strcpy(*(a + i), s);
		++i;
	}
	max_el = i;

	printf("\nQuicksorting (%d words) ... (%d pivots)\n", max_el, n_piv);
	quicksort(a, a + max_el - 1, n_piv);
	printf("List after sort:\n");
	print_list(a, a + max_el - 1);

	for (i = 0; i < max_el; ++i) {
		free(*(a + i));
	}

	return 0;
}
