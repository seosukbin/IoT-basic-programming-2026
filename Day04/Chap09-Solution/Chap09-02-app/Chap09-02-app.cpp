// 변수의 주소

#include <stdio.h>

int main(void) {
	int a = 100;      // int형 변수 선언 4byte
	double b = 300;   // double형 변수 선언 8byte
	char c = 12;      // char형 변수 선언 1byte

	// & 메모리 주소를 나타내는 연산자
	printf("int형 변수 a의 주소 : %u\n", &a);   // 주소연산자
	printf("double형 변수 b의 주소 : %u\n", &b);
	printf("char형 변수 c의 주소 : %u\n", &c);

	return 0;
}