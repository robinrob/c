/* Demonstrates using pipes from within a C program.
 * It executes the system command 'ls' and converts
 * its output to uppercase.
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int c;
	FILE *ifp;

	ifp = popen("ls", "r");
	while ((c = getc(ifp)) != EOF) {
		putchar(toupper(c));
	}
	pclose(ifp);

	return 0;
}
