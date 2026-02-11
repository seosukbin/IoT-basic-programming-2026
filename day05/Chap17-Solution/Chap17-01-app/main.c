//구조체 시작
#include <stdio.h>
struct student
{
	int num;
	double grade;

}; // 세미콜론은 필수


int main(void)
{
	struct student st1; //구조체 student형 변수로 선언
	st1.num = 2;
	st1.grade = 4.5;

	printf("학번: %d\n", st1.num);
	printf("학점: %.1f\n", st1.grade);
	return 0;
}