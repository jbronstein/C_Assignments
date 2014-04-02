#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
	char *last;
	char *first;
	float gpa;
 } Student;

void print_students(Student * students, int n);
void sort_students_by_name(Student * students, int n);
void sort_students_by_gpa(Student * students, int n);
int compareName (const void *a, const void *b);
int compareGPA(const void *c, const void *d);

int main(void)
{
	Student students[4];

	students[0].last = "Tramm";
	students[0].first= "John";
	students[0].gpa = 1.9;

	students[1].last = "Siegel";
	students[1].first= "Andrew";
	students[1].gpa = 1.8;

	students[2].last = "Tchoua";
	students[2].first= "Roselyne";
	students[2].gpa = 3.9;

	students[3].last = "Siegel";
	students[3].first= "Robert";
	students[3].gpa = 3.95;

	printf("Unsorted Students:\n");
	print_students(students, 4);

	printf("Students sorted by name:\n");
	sort_students_by_name(students, 4);
	print_students(students, 4);

	printf("Students sorted by gpa:\n");
	sort_students_by_gpa(students, 4);
	print_students(students, 4);

	return 0;
}

void print_students(Student * students, int n)
{
	int i;
	for( i = 0; i < n; i++ )
	{
		char * full = (char *) malloc( 50 * sizeof(char ) );
		sprintf(full, "%s, %s", students[i].last, students[i].first);
		printf("Name: %-20s GPA: %.2f\n", full, students[i].gpa);
	}
}

/*Run Qsort on students using compareName function */
void sort_students_by_name(Student * students, int n)
{
	qsort (students, n, sizeof(Student), compareName);
}

/*Run Qsort on students using compareGPA */
void sort_students_by_gpa(Student * students, int n)
{
	qsort (students, n, sizeof(Student), compareGPA);
}

/*compare last name, if its the same, then compare the first name*/
int compareName(const void *a, const void *b){
	int result;

	Student *ia = (Student *)a;   
	Student *ib = (Student *)b;

	/*string compare both last names*/
	result = strcmp(ia->last, ib->last);	

	if (result == 0){
		result = strcmp(ia->first, ib->first);
		}
	return result;	
}

/*compare the GPAs, lower GPA sorts first*/
int compareGPA(const void *c, const void *d){
	float one;
	float two;
	Student *ic = (Student *)c;
	Student *id = (Student *)d;
	
	one = ic->gpa;
	two = id->gpa; 

	if (one > two){
		return 1;
	}
	return 0;
}

