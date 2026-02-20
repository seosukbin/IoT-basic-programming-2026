// 주소록 프로그램 step1

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 함수 선언
static void print_menu(void);   // 이 소스내에서만 쓰겠다
static int read_menu(void);

int main(void) {
	int choice = 0;

	while (1) { // 무한루프 : 
		print_menu(); // 메뉴를 출력
		choice = read_menu(); // choice 값에 입력 받음

		switch (choice) {
		case 1:
			printf("%s\n", "[ADD] 연락처 추가 (기능 구현요)");
			break;

		case 2:
			puts("[LIST] 연락처 목록");
			break;

		case 3:
			puts("[SEARCH] 연락처 검색");
			break;

		case 4:
			puts("[EDIT] 연락처 수정");
			break;

		case 5:
			puts("[DELETE] 연락처 삭제");
			break;

		case 6:
			puts("프로그램 종료");
			return 0;

		default:
			puts("메뉴는 1~6사이 입니다.");
			break;
		}

		puts("");
	}

	return 0;
}

static void print_menu(void) {
	puts("========================================");
	puts("          주소록 프로그램 (Step 1)      ");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색");
	puts("4. 수정");
	puts("5. 삭제");
	puts("6. 종료");
	puts("----------------------------------------");
}

static int read_menu(void) {
	int choice, ch;

	printf("선택 > ");
	if (scanf("%d", &choice) != 1) {
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		return -1;
	}

	// scanf 뒤에 있는 버퍼에 엔터값 제거
	while ((ch = getchar()) != '\n' && ch != EOF) {}

	return choice;
}