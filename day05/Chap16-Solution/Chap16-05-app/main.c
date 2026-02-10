//동적할당문자열 처리 함수 사용
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_str(char**);
void print_str2(char**, int);

int main(void)
{
	char temp[80];
	char* str[21] = { 0 };
	int i = 0;
	while (i < 20) // 최대 20개까지 입력 하겠다
	{
		printf("문자열을 입력 하세요: ");
		gets(temp);
		if (strcmp(temp, "end") == 0)
		{
			break; //문자열 end 입력하면 중간에 입력 종료

		}
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}




	print_str(str); // str 전체를 매개 변수로 전달 하겠다

	print_str2(str, i);

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	return 0;

}

void print_str(char** ps)
{
	while (*ps != NULL)
	{
		printf("%s\n", *ps);
		ps++;
	}
}


void print_str2(char** ps, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%s\n", *(ps + i));
		
	}
}