/* Executes one of two programs decided by input
 * from the user using the execl() function.
 *
 * Note: when a process is successfully overlaid,
 * there is no return to the parent - the new process
 * takes over completely!
 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int choice = 0;

	printf("%s\n%s\n%s",
			"The parent process will be overlaid.",
			"You have a choice.",
			"Input 1 or 2: ");
	scanf("%d", &choice);
	putchar('\n');

	if (choice == 1) {
		execl("../programs/pgm1", "pgm1", "Hello", "Robin!", 0);
	}
	if (choice == 2) {
		execl("../programs/pgm2", "pgm2", "1", "2", "3", "go", 0);
	}
	printf("ERROR: You did not input 1 or 2.\n");

	return 0;
}
