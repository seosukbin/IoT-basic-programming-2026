//헤더 파일 사용

#include <stdio.h> 
#include "student.h" //사용자 헤더파일은 ""로 추가해야 된다

//매크로 정의
#define PI 3.14159265359
#define LIMIT 100.0
#define MSG "passed"
#define ERR_PRN printf("허용 범위 초과!!");

#define VER 6
#define BIT16

void func(void);

int main(void)
{
	Student st1 = { 315,"홍길동" };
	double radius, area;

	int max;
#if VER>=6;
	printf("버전 %d입니다.\n", VER);

#else
#error 컴파일러 버전은 6.0이사이어야 합니다
	printf("버전을 확인 하세요.\n");
#endif

#ifdef BIT16
	max = 32767;

#else
	max = 2147483647;

#endif


	printf("학번: %d, 이름: %s\n", st1.num, st1.name);
	radius = 5;
	area = radius * radius * PI;
	if (area > LIMIT) //계산딘 면적이 100.0이 넘으면
	{
		ERR_PRN;	// 오류가 뜬다
	}
	else
	{
		printf("컴파일(빌드)날짜와 시간: %s,%s\n", __DATE__, __TIME__);
		printf("파일명: %s\n", __FILE__);
		printf("함수명: %s\n", __FUNCTION__);
		printf("원 면적: %.21f(%s)\n", area, MSG);
	}
	return 0;
}