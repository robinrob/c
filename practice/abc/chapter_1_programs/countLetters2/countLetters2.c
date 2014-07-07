/* Counts total letters in input ignorning case. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	FILE *infile, *outfile; //Pointer to system-defined type FILE.
	int letter[26], i; //letter[26] stores the letter counts.
	char c;

	if (argc != 3)
		printf("Usage: %s %s %s", argv[0], "infile", "outfile\n");

	infile = fopen(argv[1], "r"); //Opens the input file in read-only mode.

	//Initialises the counting array.
	for (i = 0; i < 26; ++i)
		letter[i] = 0;
	//Reads characters from the input file and counts them.
	while ((c = getc(infile)) != EOF) {
		if ((c >= 'a') && (c <= 'z'))
			letter[c - 'a']++; //Difference in ASCII code from 'a' gives a lower-case letter's array index.
		else if ((c >= 'A') && (c <= 'Z'))
			letter[c - 'A']++; //Difference in ASCII code from 'A' gives an upper-case letter's array index.
	}
	fclose(infile);  //Closes the input file.

	outfile = fopen(argv[2], "w"); //Opens the output file in write mode.
	for (i = 0; i < 26;) {
		fprintf(outfile, "%c/%c: %d ", 'a' + i, 'A' + i, letter[i]); //Prints to the output file.
		++i;
		if ((i % 6) == 0)
			fprintf(outfile, "\n");
	}
	fclose(outfile); //Closes the output file.

	return 0;
}
