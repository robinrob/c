/* Scrambles input text using a mathematical function. */

#include "functions.h"

char scramble(char c);

int main(int argc, char* argv[])
{
	char c;
	FILE *infile, *outfile;

	if (argc != 3) {
		printf("Usage: %s %s %s\n%s\n", argv[0], "infile", "outfile",
				"The text in infile will be scrambled according\n"
				"to a certain rule and rewritten in outfile.");
		exit(0);
	}

	infile = fopen(argv[1], "r");
	outfile = fopen(argv[2], "w");
	while ((c = getc(infile)) != EOF) {
		if (is_alphanumeric(c))
			fprintf(outfile, "%c", c = scramble(c));
		else
			fprintf(outfile, "%c", c);
	}
	fclose(infile);
	fclose(outfile);

	return 0;
}

char scramble(char c)
{
	if (is_lower_case(c))
		c = (((c + 5) - 'a') % (26)) + 'a';
	else if (is_upper_case(c))
		c = (((c + 11) - 'A') % (26)) + 'A';
	else if (is_numeric(c))
		c = (((c + 3) - '0') % (10)) + '0';
	return c;
}
