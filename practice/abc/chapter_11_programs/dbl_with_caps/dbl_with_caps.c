/* Demonstrates use of temporary files. The program
 * reads in a file, capitalising all the characters
 * and stores them in a temporary file. The contents
 * of the temporary file are then appended to the bottom
 * of the input file.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

FILE *gfopen(char *filename, char *mode);

int main(int argc, char **argv)
{
	int c;
	FILE *fp, *tmp_fp;

	if (argc != 2) {
		fprintf(stderr, "\n%s%s%s\n\n%s\n\n",
				"Usage: ", argv[0], " filename",
				"The file will be doubled and letters capitalised.");
		exit(1);
	}

	fp = gfopen(argv[1], "r+");
	tmp_fp = tmpfile();

	while ((c = getc(fp)) != EOF) {
		putc(toupper(c), tmp_fp);
	}
	rewind(tmp_fp);
	fprintf(fp, "---\n");
	while ((c = getc(tmp_fp)) != EOF) {
		putc(c, fp);
	}

	return 0;
}

FILE *gfopen(char *filename, char *mode)
{
	FILE *fp;

	if ((fp = fopen(filename, mode)) == NULL) {
		fprintf(stderr, "Cannot open %s - bye!\n", filename);
		exit(1);
	}
	return fp;
}
