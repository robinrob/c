/* error.c
 *
 * Error functions.
 */

#include "base_change.h"

/* Exits program with a message. */
void error_exit(const char *str)
{
	printf("ERROR: %s, exiting.\n", str);
	exit(1);
}

