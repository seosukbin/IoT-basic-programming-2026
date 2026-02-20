// 구조체, 공용체 재정의

#include <stdio.h>

struct student {
	int num;
	double grade;
};

// 타입 재정의. struct student가 너무 길다....
typedef struct student Student;   // 이제부터 Student만 쓰면 구조체를 선언
void print_data(Student*);

int main(void) {
	Student st1 = {
		.num = 315,
		.grade = 4.3
	};  // struct student st1와 동일

	print_data(&st1);

	return 0;
}

void print_data(Student* ps) {
	printf("학번 : %d\n", ps->num);
	printf("한점 : %.1f\n", ps->grade);
	printf("한점 : %.1f\n", (*ps).grade);
}