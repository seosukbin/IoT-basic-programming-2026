// 포인터 크기

#include <stdio.h>

int main(void) {
	char ch; // 문자형 변수
	int in;  // 정수형 변수
	double db;  // 실수형 변수

	// 선언 및 초기화
	char* pch = &ch;
	int* pin = &in;
	double* pdb = &db;

	// 주소크기 출력
	// 윈도우가 64비트 => 8byte x 8bit == 64bit
	// 현재 윈도우의 주소체계는 8byte
	printf("char형 변수 주소 크기 : %zu bytes\n", sizeof(&ch));  //  8
	printf("int형 변수 주소 크기 : %zu bytes\n", sizeof(&in));  // 8
	printf("double형 변수 주소 크기 : %zu bytes\n", sizeof(&db)); // 8

	// 포인터크기 -> 변수의 주소를 담아야 하므로 모두 8byte
	printf("char형 *변수 크기 : %zu bytes\n", sizeof(pch));
	printf("int형 *변수 크기 : %zu bytes\n", sizeof(pin));
	printf("double형 *변수 크기 : %zu bytes\n", sizeof(pdb));

	// 포인터가 가리키는 변수 크기
	printf("char형 * 가리키는 변수 크기 : %zu bytes\n", sizeof(*pch));  // 1
	printf("int형 * 가리키는 변수 크기 : %zu bytes\n", sizeof(*pin)); // 4
	printf("double형 * 가리키는 변수 크기 : %zu bytes\n", sizeof(*pdb)); // 8

	// 일반변수 크기
	printf("char형 변수 크기 : %zu bytes\n", sizeof(ch));
	printf("int형 변수 크기 : %zu bytes\n", sizeof(in));
	printf("double형 변수 크기 : %zu bytes\n", sizeof(db));


	return 0;
}