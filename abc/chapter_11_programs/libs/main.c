#include "g_lib.h"
#include <ctype.h>

int main(void)
{
    char *s = gcalloc(11, sizeof(char));
    s = "Hello Robin";
    printf("%s\n", s);
    FILE *file = gfopen("out.txt", "w");
    fprintf(file, "Hello Robin");
    fclose(file);
    return 0;
}
