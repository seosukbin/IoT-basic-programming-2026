#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고 제거
#include <stdio.h>

int main(void)
{
	char str2[5];
	char str[80];

	printf("문자열 입력: ");
	gets(str);
	//scanf("%s", str);
	printf("입력한 문자열: %s\n", str);
	return 0;

}