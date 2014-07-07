/* Decodes text scrambled by word_scrambler. */

#include "functions.h"

char decode(char c);

int main(int argc, char* argv[])
{
	FILE *infile, *outfile;
	char c;

	if (argc != 3) {
		printf("Usage: %s %s %s\n%s", argv[0], "infile", "outfile",
				"The text in infile will be decoded according to"
				"the correct rule and the decoded text written"
				"in outfile.");
		exit(0);
	}

	infile = fopen(argv[1], "r");
	outfile = fopen(argv[2], "w");
	while ((c = getc(infile)) != EOF) {
		if (is_alphanumeric(c))
			fprintf(outfile, "%c", decode(c));
		else
			fprintf(outfile, "%c", c);
	}
	fclose(infile);
	fclose(outfile);

	return 0;
}

char decode(char c)
{
	if (is_lower_case(c))
		c = ((c + (26 - 5) - 'a') % (26)) + 'a';
	else if (is_upper_case(c))
		c = ((c + (26 - 11) - 'A') % (26)) + 'A';
	else if (is_numeric(c))
		c = ((c + (10 - 3) - '0') % (10)) + '0';
}
