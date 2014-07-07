/* The main() function in this program returns an
 * integer status value which can be used by a shell
 * script executing it.
 */

#include <stdio.h>

#define MARKER ">> "

int main(int argc, char **argv)
{
	int val;

	printf("\n");
	printf(MARKER "   Input an integer: ");
	scanf("%d", &val);
	printf(MARKER "Value being returned: %d\n\n", val);
	return val;
}
