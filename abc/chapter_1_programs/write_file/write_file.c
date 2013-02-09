/* Takes in a string input from the user and writes it to a file. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char p;
    FILE *file; //Bbuilt-in type FILE defined in stdio.h

    file = fopen("testFile.txt", "w"); //Opens the output file in write mode.

	printf("%s\n%s",
			"Enter some text to save to 'textFile.txt'",
			"and press enter:\n");

	//Reads in characters and writes them to the output file.
	while (scanf("%c", &p))
		putc(p, file);
	fclose(file); //Closes the output file.

	return 0;
}
