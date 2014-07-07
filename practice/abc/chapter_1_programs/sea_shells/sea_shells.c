/* Exercise to make sea shells message. */

#include <stdio.h>

int main(void)
{
	printf("\n");
	printf("%s\n", "She sells sea shells by the sea shore");
	printf("%s\n%s\n%s\n", "She sells", "sea shells", "by the sea shore");
	printf("%s\n%s%10s%s\n%s%10s%s\n%s%10s%s\n%s%10s%s\n%s\n",
			"##############",
			"# ", "She sells", " #",
			"# ", "sea shells", " #",
			"# ", "by the sea", " #",
			"# ", "shore", " #",
			"##############");
	printf("\n");

	return 0;
}
