#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	printf("작업 진행");
	for (i = 0; i < 10; i++)
	{
		printf(".");
		fflush(stdout);
		Sleep(500); // 0.5초씩 대기
	}
	printf("완료!");
	return 0;
}