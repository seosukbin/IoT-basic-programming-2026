//입력용 소스 코드
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//extern은 외부에 있는것을 가져 와라

extern int count; // main.c에 있는 변수를 공유
int total;

int input_data(void)
{
	int pos;
	while (1)
	{
		printf("양수 입력:");
		scanf("%d,",&pos);
		if (pos < 0)
		{
			break;
		}
		count++;
		total += pos;

	}
	return total;

}