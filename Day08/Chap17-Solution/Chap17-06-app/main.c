#include <stdio.h>

struct student
{
	int num;
	double grade;
};

typedef struct student Student;
void print_data(Student*);
int main(void)
{
	Student st1 = {
	.num = 315,
	.grade = 4.3
	};
	print_data(&st1);
	return 0;
}

void print_data(Student* ps)
{
	printf("학번: %d\n", ps->num);
	printf("한점: %.1f\n", ps->grade);
	printf("한점: %.1f\n", (*ps).grade);

}