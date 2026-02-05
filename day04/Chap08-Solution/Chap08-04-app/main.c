#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고 제거
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[80] = "applejam"; // 문자열을 출력할때는 마지막에 무조건 null이 필요하다.
	printf("최초 문자열: %s\n", str);
	printf("문자열 입력: ");
	
	strcpy(str, "grape");
	printf("입력후 문자열: %s\n", str);
	return 0;
	
}