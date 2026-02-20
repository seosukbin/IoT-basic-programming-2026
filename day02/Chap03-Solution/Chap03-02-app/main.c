// 실수형 
#define _CRT_SECURE_NO_WARNINGS  // 보안문제 이전의 오래된 함수사용을 위해서

#include <stdio.h>
#include <float.h>   // 실수형 표현을 위한 라이브러리 
#include <string.h>   // 문자열 처리를 위한 라이브러리

int main(void) {
	// float 4bytes 
	printf("변수 float, %zu byte, 최소 %e, 최대 %e\n", sizeof(float), FLT_MIN, FLT_MAX);
	// double 8bytes
	printf("변수 double, %zu byte, 최소 %e, 최대 %e\n", sizeof(double), DBL_MIN, DBL_MAX);

	// 문자열 : 문자의 배열(char array)
	// 문자를 표현할 때는 ''
	// 문자열을 표현할 때는 "
	char fruit[20] = "strawberry"; // 절대 'strawberry' 사용불가

	printf("과일 이름 : %s\n", fruit);

	//fruit = "banana"; 문자열에서 대입은 불가
	strcpy(fruit, "banana");  // 함수를 사용해서 변수값을 변경
	printf("변경 과일 이름 : %s\n", fruit);

	// const : 변하지 않는 값을 지정
	const double tax_rate = 0.10; // 세율
	const double pi = 3.141592; // 원주율이 바뀌나요?
	int income = 5000;
	double tax = income * tax_rate;
	printf("세금은 %f원\n", tax);

	//tax_rate = 0.20; // const는 이후에 변경 불가

	// 변수 선언에서 조심할 것
	int age;  // unsigned char(최대값 255) 가 가장 적합

	/*
	* 변수명 지정방식
	* 알파벳 A-Z, a-z, 0~9, _ 까지만 허용
	* 숫자로 시작할 수 없음
	* 대소문자 구별
	* 예약어는 변수명으로 사용 불가
	*
	* 의미있는 단어들의 조합으로 변수명 선언할 것
	*/
	char full_name[50] = "Hugo MG Sung";
	int age = 50;
	char address[100] = "부산시 남구 용호동 356";
	char bood_type = 'B';
	float height = 178.5f;
}