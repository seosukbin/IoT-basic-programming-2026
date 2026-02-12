
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char str[80];
	char* res;
	char cwd[256];
	_getcwd(cwd, sizeof(cwd));
	printf("현재 작업 폴더: %s\n", cwd);

	//여기서 부터 텍스트 파일 복사


	FILE* fp, *ofp;
	fp = fopen("./data/sample.txt", "r");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}
	else {
		printf("파일 열기 성공\n");
	}

	ofp = fopen("./data/copy.txt","w");
	if (ofp == NULL)
	{
		printf("출력 파일 열기 실패\n");
		return 1;
	}

	while (1)
	{
		res = fgets(str, sizeof(str), fp);
		if (res == NULL)
		{
			break;
		}
		printf("한줄 쓰기->%s\n", str);
		str[strlen(str) - 1] = '\0'; //null은 없애고
		fputs(str, ofp);
		fputs(" ", ofp); // 이걸로 한칸씩 띄었다
	}

	fclose(fp); 
	fclose(ofp);
	return 0;
}