// 지역변수, 전역변수 

#include <stdio.h>

void assign(void);

int a;   // 전역변수

int main(void) {

	auto int a = 10;   // 지역변수, auto 생략 가능
	int b = 20;

	assign();
	printf("main 함수 a : %d\n", a);

	printf("교환전 %d, %d\n", a, b);
	{
		int a = 0, b = 0, temp; // 블록내 지역변수가 우선적으로 쓰임.
		temp = a;
		a = b;
		b = temp;
	}

	printf("교환후 %d, %d\n", a, b);

	return 0;
}

void assign(void) {
	int a;

	a = 100;
	printf("assign 함수 a : %d\n", a);
}