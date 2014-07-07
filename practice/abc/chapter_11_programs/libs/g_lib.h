/* Header file for g_lib.a library. */

#include <stdio.h>
#include <stdlib.h>

void *gcalloc(int n, unsigned sizeof_something);
FILE *gfopen(char *filename, char *mode);
