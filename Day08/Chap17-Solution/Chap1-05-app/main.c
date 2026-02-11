// 공용체
// 구조체와 유사하지만 하나의 저장공간을 같이 사용한다.
#include <stdio.h>


//struct student 16byte 사용

enum season { SPRING, SUMMER, FALL, WINTER };

union student
{
	char ch1;
	int num;
	double grade;
};

int main(void)
{
	union student st1 = { .num = 315 };

	printf("공용 사이즈%zu\n", sizeof(st1));
	printf("학번: %d\n", st1.num);
	st1.grade = 4.4;
	printf("학점: %.1f\n", st1.grade);
	printf("학번: %d\n", st1.num); // 공용체이기 때문에 하나의 저장 공간을 사용한다 그래서 현재 double로 바꿨기 때문에
	// 8바이트를 사용하는데 밑에는 int로 하였기 때문에 쓰레기 값이 나온다.

	enum season ss;
	char* pc = NULL;
	ss = SUMMER;
	switch (ss) {
	case SPRING:
		pc = "inline";
		break;
	case SUMMER:
		pc = "SWIMMING";
		break;
	case FALL:
		pc = "tracking";
		break;
	case WINTER:
		pc = "skiing";
		break;

	}
}
