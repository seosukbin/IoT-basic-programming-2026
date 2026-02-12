// 파일 입출력 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* ifp, * ofp;
	char name[20];
	int kor, eng, math;
	int total = 0;
	double avg;
	int res;

	ifp = fopen("./orginal.txt", "r"); // r모드는 파일 없으면 실패
	if (ifp == NULL)
	{
		printf(u8"입력 파일 오픈 실패\n");
		exit(1);

	}
	ofp = fopen("./copy.txt", "w"); // w쓰기 모드는 파일이 없으면 파일 생성

	if (ofp == NULL)
	{
		printf("출력 파일 생성 실패\n");
		exit(1);
	}
	while (1)
	{	// 입력 파일 포인터엣 읽어서 한줄씩 각 변수에 할당
		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
		if (res == EOF) 
		{
			break;
		}
		total = kor + eng + math;
		avg = total / 3.0;
		printf("%s%5d%7.1f\n", name, total, avg); 

	}
	printf("파일 복사 완료\n");
	fclose(ifp); 
	fclose(ofp);


}