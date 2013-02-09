/* A Program to sort structures by their integer field. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_P 20
#define MAX_NAME 20

//struct person has a string name and an integer age.
typedef struct {
    char name[MAX_NAME];
    int age;
} person;

//Comparison function to be used with qsort().
int cmp(const void *vp, const void *vq);
//Function to print a list of people.
void print_people(person p[], int n);

int main(void)
{
	int i;
    person arr[MAX_P];
    
    i = 0;
    //Read in the data for names and ages.
    while (scanf("%s", arr[i].name) == 1) {;
    	scanf("%d", &(arr[i].age));
    	++i;
    }
    const int n_p = i;

    //Print the unsorted array of people.
    printf("people (unsorted):\n");
    print_people(arr, n_p);

    //Sort the people using qsort() and cmp().
    qsort(arr, n_p,  sizeof(person), cmp);

    //Print the sorted array of people.
    printf("people (sorted):\n");
    print_people(arr, n_p);

    return 0;
}

//Comparison function to give to qsort().
int cmp(const void *vp, const void *vq)
{
	/* Cast must be used to access the 'age' field of
	 * a person.
	 */
	const int *p = &(((person *) vp) -> age);
	const int *q = &(((person *) vq) -> age);
	int diff = *q - *p;
	return ((diff >= 0) ? ((diff > 0) ? -1 : 0) : +1);
}

void print_people(person p[], int n)
{
	int i;
    for (i = 0; i < n; ++i) {
    	printf("person %d: %s, %d\n", i, p[i].name, p[i].age);
    }
}
