/* Demonstrating use of structures to check the number of
 * failing students in a class of randomly-created students.
 */

#include <stdio.h>
#include <stdlib.h>

#define CLASS_SIZE 100

//Student structure
struct student {
    char *last_name;
    int student_id;
    char grade;
};

//New type student
typedef struct student student;

int n_fail(student class[]);

int main(void)
{
    int i;
    student class[CLASS_SIZE];
    
    srand(time(NULL));
    
    for (i = 0; i < CLASS_SIZE; ++i) {
	class[i].grade = 'A' + (rand() % 6);
    }
    
    printf("Number of students failed: %d\n", n_fail(class));
    
    return 0;
}

//Returns the number of fail grades in a given class.
int n_fail(student class[])
{
    int i, cnt = 0;
    for (i = 0; i < CLASS_SIZE; ++i) {
	cnt += class[i].grade == 'F';
    }
    return cnt;
}
