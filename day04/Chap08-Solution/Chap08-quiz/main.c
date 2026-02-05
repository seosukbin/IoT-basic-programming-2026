// 대소문자 변환 프로그램
	#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고 제거
	#include <stdio.h>
	int main(void)
	{
		char str[80];
		int i;
		int count = sizeof(str) / sizeof(str[0]);

		int pos;
		int num = 0;


		printf("문자열 입력: ");
		gets(str); //scanf대신 문자열을 입력 받는 함수이다 \n이 나오기전까지 입력을 받는다
		for (i = 0; i < count; i++)
		{
			if (str[i] == '\0')
			{
				pos = i;
				break;
			}
		}
		for (i = 0; i < pos; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z') // 문자 한자가 A에서 Z 사이에 있으면s
			{
				str[i] = str[i] + 32;
				num++;
			}
		}
		printf("바뀐 문장: ");
		puts(str);
		printf("바뀐 대문자 개수: %d\n", num);
		printf("null의 위치: %d\n", pos);

		return 0;

	}