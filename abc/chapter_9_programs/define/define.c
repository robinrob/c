/* A program where a typedef can be swapped for a #define
 *for the same effect.
 */

#include <stdio.h>

//typedef float DOLLARS;
#define DOLLARS float

int main(void)
{
    DOLLARS amount = 100.0, interest = 0.07 * amount;
    
    printf("DOLLARS = %.2f\n", amount + interest);
    return 0;
}
