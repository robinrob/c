/* This program demonstrates using system() to
 * execute a system command. The output of the
 * system command is printed out in lower case.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSTRING 100

int main(void)
{
	char command[MAXSTRING], *tmp_filename;
	int c;
	FILE *ifp;

	tmp_filename = tmpnam(NULL);
	sprintf(command, "ls > %s", tmp_filename);
	system(command);
	ifp = fopen(tmp_filename, "r");
	while ((c = getc(ifp)) != EOF) {
		putchar(tolower(c));
	}
	remove(tmp_filename);

	return 0;
}
