// 함수 포인터 활용
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 함수선언
void func(int (*fp)(int, int)); // 함수 포인터를 매개변수로 가지는 함수
int sum(int, int);
int mul(int, int);
int max(int, int);

// 메인함수 정의
int main(void) {
	int sel;   // 메뉴 선택한 값

	// 콘솔메뉴
	printf("01 두 정수의 합\n");
	printf("02 두 정수의 곱\n");
	printf("03 두 정수중 최대값\n");
	printf("원하는 연산을 선택 : ");
	scanf("%d", &sel);  // scanf는 변수의 주소! 

	switch (sel) {
	case 1:
		printf("더하기 연산!");
		func(sum);
		break;
	case 2:
		printf("곱하기 연산!");
		func(mul);
		break;
	case 3:
		printf("최대값 연산!");
		func(max);
		break;
	}

	return 0;
}

void func(int (*fp)(int, int)) {
	int x, y;
	int res;

	printf("두 정수 값을 입력하세요 : ");
	scanf("%d%d", &x, &y);
	res = fp(x, y);
	printf("결과 : %d\n", res);
}

int sum(int x, int y) {
	return x + y;
}

int mul(int x, int y) {
	return x * y;
}

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}