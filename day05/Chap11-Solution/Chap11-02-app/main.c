//문자 입력 실수
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	//char ch1, ch2,ch3;
	
	//scanf_s("%c%c", &ch1, &ch2);
	//printf("[%c%c]", ch1, ch2);
	
	
	//ch1 = getchar();// getchar는 앞선 입력의 \n도 들어갈수 있다
	//	putchar(ch1);
	int num, grade;
	printf("학번 입력: ");
	scanf_s("%d", &num);
	printf("학점 입력: ");
	grade = getchar();
	printf("학번: %d, 학점: %d\n", num, grade);
	return 0;
}