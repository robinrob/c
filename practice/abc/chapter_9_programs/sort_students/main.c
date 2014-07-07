/* A program to sort a list of class which each have
 * a name, student number and a grade. class are sorted
 * by grade and those that have the same grade are sorted
 * alphabetically by name.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 15
#define MAX_LIST 20

typedef struct
{
	char name[MAX_NAME];
	int number;
	char grade;
} student;

void print_class(student *arr, int n);
int read_name(char *name);
int read_grade(char *c);
int is_tab(char c);
int cmp_grades(const void *vp, const void *vq);
int cmp_names(const void *vp, const void *vq);
void sort(student class[], int n);
char class_avg(student *class, int n);

int main(void)
{
	student *class = calloc(MAX_LIST, sizeof(student));
	int i;

	i = 0;
	//Read in the student data.
	while (read_name(class[i].name))
	{
		scanf("%d", &(class[i].number));
		read_grade(&(class[i].grade));
		++i;
	}
	const int n_s = i;

	printf("class (unsorted):\n");
	print_class(class, n_s);

	sort(class, n_s);

	printf("class (sorted):\n");
	print_class(class, n_s);

	printf("average grade: %c\n", class_avg(class, n_s));

	return 0;
}

/* Reads in a name for a student from the
 * input stream, up to a following tab.
 */
int read_name(char *name)
{
	char c;
	int i;

	i = 0;
	while ((c = getchar()) != EOF) {
		if (is_tab(c)) {
			break;
		}
		else if (c == '\n') {
			continue;
		}
		name[i] = c;
		++i;
	}
	if (i == 0) {
		return 0;
	}
	else {
		name[i] = '\0';
		return 1;
	}
}

/* Reads in a grade for a student from the input stream
 * and assigns it to c.
 */
int read_grade(char *c)
{
	while ((*c = getchar()) != EOF) {
		if (*c != 9) {
			return 1;
		}
	}
	return 0;
}

//Prints an array of class.
void print_class(student *arr, int n)
{
	int i;
	for (i = 0; i < n; ++i) {
		printf("name: %15s, number: %2d, grade: %c\n",
				(arr + i) -> name,
				((arr + i) -> number),
				((arr + i) -> grade));
	}
}

//Checks whether or not a given character is a tab.
int is_tab(char c) {
	if (c == 9) {
		return 1;
	}
	else {
		return 0;
	}
}

//Comparison function for sorting grades.
int cmp_grades(const void *vp, const void *vq)
{
	const char *p = &(((student*) vp) -> grade);
	const char *q = &(((student*) vq) -> grade);
	int diff = *q - *p;
	return ((diff >= 0) ? ((diff > 0) ? -1 : 0) : +1);
}

//Comparison function for sorting names.
int cmp_names(const void *vp, const void *vq)
{
	const char *p = (char *) &(((student *) vp) -> name);
	const char *q = (char *) &(((student *) vq) -> name);
	int diff = strcmp(q, p);
	return ((diff >= 0) ? ((diff > 0) ? -1 : 0) : +1);
}

//Sorts all class by grade and by name.
void sort(student class[], int n)
{
	int i, cnt;
	char grade;
	qsort(class, n, sizeof(student), cmp_grades);
	grade = class[0].grade;
	for (i = 1, cnt = 0; i < n; ++i) {
		if (class[i].grade == grade) {
			++cnt;
		}
		else {
			qsort(class + i, cnt, sizeof(student), cmp_names);
			cnt = 0;
			grade = class[i].grade;
		}
	}
}

/* Calculates and returns the average grade
 * of the class.
 */
char class_avg(student *class, int n)
{
	int i, sum;
	for (i = 0, sum = 0; i < n; ++i) {
		sum += (class[i].grade - 'A');
	}
	return (char) ('A' + sum / n);
}

