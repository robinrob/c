/* Demonstrating implementation of a word list by using a pointer to array of char. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 30
#define MAXWORD 50

int main(void)
{
	char *c[N];
	int n, i;
	
	printf("Enter n: ");
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		c[i] = calloc(MAXWORD + 1, sizeof(char));
		strcpy(c[i], "robin smith :)");
		printf("%s\n", c[i]); 
	}
	
	for (i = 0; i < MAXWORD; ++i) {
		if (*(c[0] + i) != '\0') {
			printf("%c\n", *(c[0] + i));
		}
	}
	//printf("\n");
	
	for (i = 0; i < n; ++i) {
		free(c[i]);
	}
	
	return 0;
}
