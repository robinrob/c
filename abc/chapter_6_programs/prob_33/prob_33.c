/* A program that does some stuff with a double array
 * and various pointer arithmetic
 */
 
#include <stdio.h>

int main(void)
{
	int a[3][5], i, j, *p = *a;
	
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 5; ++j) {
			a[i][j] = i * 5 + j;
		}
	}
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 5; ++j) {
			printf("%s%12d", (j == 0) ? "\n" : "", a[i][j]);
		}
	}
	printf("\n");
	for (i = 0; i < 15; ++i) {
		printf("%s%12d", (i % 5 == 0) ? "\n" : "", *(p + 1));
	}
	printf("\n\n%12d%12d\n%12d%12d\n%12d%12d\n%12d%12d\n\n",
		   **a, **(a + 1),					//0 5
		   *(a[0] + 1), *(*a + 1),		 	//1 1
		   *(a[1] + 2), *(*(a + 1) + 2),	//7 7
		   *(a[2] + 3), *(*(a + 2) + 3));	//13 13
		   
	printf("%-11s%s%12d\n%-11s%s%12d\n%-11s%s%12d\n\n",
		   "(int) a", " = ", (int) a,       //address of whole array
		   "(int) *a", " = ", (int) *a,		//address of first array (same as above)
		   "(int) **a", " = ", (int) **a);	//0
		   
		   
	return 0;
}
