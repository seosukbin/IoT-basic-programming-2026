#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int x = 10; //전역 변수
void func(void);
int add(int);

int main(void)
{
	printf("main x = %d\n", x);
	func();
	printf("main x = %d\n", x);

	int a = 1;
	if (a == 1)
	{
		int b = 2;
		printf("블록 내부: a = %d , b = %d\n", a, b);// 블록 내부에서 선언한 변수 b는 블록 밖에서 사용 불가이다. 

	}
	printf("블록 외부: a = %d \n", a);
	int y = 10;
	add(y);
	printf("y = %\n", y);

	return 0;

}

void func(void)
{
	int x = 20; // 지역 변수
	printf("fun x = %d\n", 20);
}

void add(int x)
{
	int x = x + 100;
	return x;
}
