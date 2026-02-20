// 파일 입출력 + 프로그램 실행경로
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <direct.h>

int main(void) {
	char cwd[256];   // 경로 입력 변수, 윈도우 경로 문자열 최대길이. Python 설치시 확인가능

	char str[80];
	char* res;  // 2줄

	_getcwd(cwd, sizeof(cwd));
	printf("현재 작업(프로젝트) 폴더 : %s\n", cwd);

	// 여기서 부터 텍스트파일 복사
	FILE* fp, * ofp;  // fp 파일 입력용 파일포인터, ofp 출력용 파일포인터  // 3줄

	// 디렉토리, 폴더 구분자로 /를 사용해도 무방
	fp = fopen("./data/sample.txt", "r");  // 4 줄
	if (fp == NULL) {  // 실패 방지 옵션
		printf("파일 열기 실패\n");
		return 1;  // exit(1)과 동일한 기능
	}
	else {
		printf("파일 오픈 성공\n");
	}

	// 파일 복사용 오픈
	ofp = fopen("./data/copy.txt", "w");  // 5줄
	if (ofp == NULL) {  // 실패방지 옵션
		printf("출력파일 열기 실패\n");
		return 1;  // exit(1)과 동일한 기능
	}

	while (1) {
		res = fgets(str, sizeof(str), fp);  // sample.txt 읽은 파일포인터에서 한줄을 read  
		if (res == NULL) {
			break;
		} // 10줄

		printf("한줄 쓰기 -> %s\n", str);
		// str[strlen(str) - 1] = '\0';  // \n -> \0 바꿔줘서 
		fputs(str, ofp);  // 11줄 
		// fputs(" ", ofp); // 한줄 끝난뒤 스페이스 추가
	}

	printf("텍스트 파일 복사 성공!\n");

	fclose(fp);
	fclose(ofp); // 13줄

	return 0;
}