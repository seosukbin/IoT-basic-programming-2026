#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	/*
	int input_val;
	printf("정수를 입력 하세요:");
	scanf_s("%d", &input_val);  &: 주소 키보드로 입력되는 값은 input_val에 가져가서 넣어라라는 의미이다. 
	printf("입력된 값: %d\n", input_val);
	
	*/
	

	/*
	int age;
	double height;
	printf("나이와 키를 입력 하세요 : ");
	scanf_s("%d%lf", &age, &height);
	printf("나이는 %d이고 키는 %.1fcm입니다\n", age, height);
	return 0;

	*/

	//문자열 입력
	char grade;
	char name[20];
	printf("학점 입력: ");
	scanf_s("%c", &grade);
	printf("이름 입력: ");
	scanf_s("%s", name); // 배열의 이름만 적으면 배열의 주소를 나타낸다 그래서 &를 쓰지 않는다
	printf("%s의 학점은 %c입니다.\n", grade, name);
	return 0;

	
}