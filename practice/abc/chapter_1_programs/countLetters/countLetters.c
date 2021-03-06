/* Counts letters in a file & displays info about frequencies.
 *The program takes command-line arguments to specify input and output
 files.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int c, i, letter[26]; //letter[26] stores the letter counts.
	FILE *ifp, *ofp; //Pointer to system-defined type FILE.
	if (argc != 3) {
		printf("\n%s%s%s\n\n%s\n%s\n\n",
				"Usage: ", argv[0], " infile outfile",
				"The uppercase letters in infile will be counted.",
				"The results will be written in outfile.");
		exit(1);
	}

	ifp = fopen(argv[1], "r"); //Opens the input file in read-only mode.
	ofp = fopen(argv[2], "w"); //Opens the output file in write mode.
	//Initialises the counting array.
	for (i = 0; i < 26; ++i) {
		letter[i] = 0;
		if (i % 6 == 0)
			printf("\n");
		printf("%c%s%d%s", 'A' + i, ": ", letter[i], " ");
	}
	//Reads characters from the input file and counts them.
	while ((c = getc(ifp)) != EOF) //Gets a character from the input file.
		if (c >= 'a' && c <= 'z')
			++letter[c - 'a']; //Difference in ASCII code from 'a' gives a letter's array index.
	for (i = 0; i < 26; ++i) {
		if (i % 6 == 0)
			putc('\n', ofp);
		fprintf(ofp, "%c:%5d    ", 'a' + i, letter[i]); //Prints to the output file.
	}
	putc('\n', ofp); //Finishes the output file with a newline.

	fclose(ifp); //Closes the input file.
	fclose(ofp); //Closes the output file.
	ofp = fopen(argv[2], "r"); //Opens the output file in read-only mode.

	//Prints the contents of the output file to the screen.
	while ((c = getc(ofp)) != EOF)
		printf("%c", c); 

	return 0;
}
