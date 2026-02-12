// 파일 입출력 추가

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int main(void)
{
	FILE* fp;
	char str[30];
	//w와 a는 파일이 없으면 생성 한다

	fp = fopen("./test.txt", "a+");// 기존 텍스트에 추가 +는 읽고 쓰기가 둘다 가능 
	
	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		exit(1);


	}
	while (1)
	{
		printf("과일 이름 입력: ");
		scanf("%s", str); //키보드 입력
		if (strcmp(str, "end") == 0) //입력으로 end를 넣으면 종료
		{
			break;
		}
		else if (strcmp(str, "list") == 0)
		{
			fseek(fp, 0, SEEK_SET);
			while (1)
			{
				fgets(str, sizeof(str), fp);

				if (feof(fp))
					break;

				printf("%s", str);
			}
		}
		else
		{
			fprintf(fp, "%s\n", str)
		}
	}

	fclose(fp);
	printf("파일 처리 완료\n");
	
	
	
	return 0;
}