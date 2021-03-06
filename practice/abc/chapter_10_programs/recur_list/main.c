/* Use the recursive list functions to convert "ABC"
 * into a list and print it.
 */

#include "list.h"

int main(void)
{
	LINK h;

	h = string_to_list("ABC");
	printf("The resulting list is\n");
	print_list(h);
	printf("\nThis list has %d elements.\n", count(h));

	return 0;
}
