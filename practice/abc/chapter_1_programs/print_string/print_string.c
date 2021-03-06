/* Uses a custom-made function to print strings and shows how to concatenate them. */

#include <stdio.h>
#include <string.h>

#define MAXSTRING 100

void print_str(char *);
void special_print_str(char *);

int main(void)
{
	char s1[MAXSTRING], s2[MAXSTRING];
	int i;
	
	strcpy(s1, "Mary, Mary, quite contrary,\n");
	strcpy(s2, "how does your garden grow?");
	print_str(s1);
	printf("\n\n");
	print_str(s2);
	printf("\n\n");
	strcat(s1, s2);
	print_str(s1);
	printf("\n");
	return 0;
}

void print_str(char *p)
{
	for (; *p != '\0'; ++p)
		putchar(*p);
}


