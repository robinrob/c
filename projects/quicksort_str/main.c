/*Program to sort a list of words using quicksort.*/

#include "sort.h"

#define MAXLIST 200
#define MAXWORD 20

int main(int argc, char *argv[])
{
	char *a[MAXLIST], s[MAXWORD];
	int i, max_el, n_piv;

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

//	printf("List before sort:\n");
//	print_list(a, a + max_el - 1);
	printf("\nQuicksorting (%d words) ... (%d pivots)\n", max_el, n_piv);
	quicksort(a, a + max_el - 1, n_piv);
	printf("List after sort:\n");
	print_list(a, a + max_el - 1);

	for (i = 0; i < max_el; ++i) {
		free(*(a + i));
	}

	return 0;
}
