/* Demonstrates file input/output by
 * double-line spacing a file.
 */

#include <stdio.h>
#include <stdlib.h>

void double_line(FILE *, FILE *);
void print_info(char *);

int main(int argc, char **argv)
{
	FILE *ifp, *ofp;

	if (argc != 3) {
		print_info(argv[0]);
		exit(1);
	}

	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "w");
	double_line(ifp, ofp);
	fclose(ifp);
	fclose(ofp);

	return 0;
}

void double_line(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
		if (c == '\n') {
			putc('\n', ofp); //Newline - duplicate it.
		}
	}
}

void print_info(char *pgm_name)
{
	printf("\n%s%s%s\n\n%s%s\n\n",
			"Usage: ", pgm_name, "infile outfile",
			"The contents of infile will be double-"
			"line spaced",
			"and written to outfile.");
}
