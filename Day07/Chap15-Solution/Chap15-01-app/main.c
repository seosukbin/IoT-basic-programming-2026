// 함수 포인터
// 함수도 변수처럼 주소를 가짐. 포인터로 활용가능
// 콜백, 대리자(이벤트) 함수 처리할 때 필요한 기능

#include <stdio.h>

int sum(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main(void) {
	int (*fp)(int, int);  // 함수 포인터 선언! 매개변수의 타입과 갯수가 일치
	int res;

	fp = sum;  // 배열의 이름만 적으면 주소. 함수의 이름만 적으면 주소를 
	//res = sum(10, 20);  // 일반적인 방식 함수 호출 가능
	res = fp(10, 20);  // 함수 포인터로 함수 호출!!
	printf("덧셈 결과 : %d\n", res);

	fp = sub;  // 함수 주소를 변경해서 fp가 뺄셈을 할 수 있게 변경
	res = fp(20, 10);
	printf("뺄셈 결과 : %d\n", res);

	fp = mul;
	res = fp(20, 10);
	printf("곱셈 결과 : %d\n", res);

	fp = div;
	res = fp(10, 2);
	printf("나눗셈 결과 : %d\n", res);


	return 0;
}

int div(int x, int y) {
	return x / y;
}

int mul(int x, int y) {
	return x * y;
}

int sum(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}