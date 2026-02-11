//배열은 자료형이 같은 변수를 메모리에 연속으로 할당한다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int ary[3];
	int i;
	*(ary + 0) = 10;
	*(ary + 1) = *(ary + 0) + 10;
	printf("세번째 배열 요소에 키보드 입력: ");
	scanf("%d", ary + 2); // ary +2 또는 &ary[2]

	for (i = 0; i < 3; i++)
	{
		printf("%5d", *(ary + i)); // %5d는 정수 자릿수를 5개로 맞추는 연산 방법이다.
		//*(ary + 0)에서 ary는 배열명이고 0은 배열 값이다. *(100)
	}

}