
#define _CRT_SECURE_NO_WARNINGS
#include "addressbook.h"

int main(void)
{
	SetConsoleOutputCP(65001);

	int choice = 0;
	if (!ab_init()) return 1; // main 함수의 1과 사용자 함수들의 return 1의 차이 비교 해야 할것

	load_contacts("contacts.txt");
	while (1)
	{
		// 메뉴를 출력 
		// choice 값에 입력을 받음

		print_menu();
		choice = read_menu();
		switch (choice)
		{
		case 1:
			//printf("%s\n", "[ADD]연락처 추가");
			add_contact(); // 연락처 추가
			break;

		case 2:
			//puts("[LIST]연락처 목록");
			list_contacts();
			break;

		case 3:
			//puts("[SEARCH]연락처 검색(다음 스텝에서)");
			search_contact();
			break;

		case 4:
			puts("[EDIT]연락처 수정");
			update_contact();
			break;

		case 5:
			//puts("[DELETE]연락처 삭제(다음 스텝에서)");
			delete_contact();
			break;
		
		case 6:
			sort_by_name();
			break;

		case 7:
			save_contacts("contacts.txt");
			ab_free();
			puts("프로그램 종료");
			return 0;

		//case 7:
		//	 save_contacts("contacts.txt");
		//	break;

		//case 8:
		//	// load_contacts("contacts.txt");
		//	break;

		default:
			puts("메뉴는 1~7사이 입니다.(다음 스텝에서)");
			break;


		}

		puts(" ");
	}

	return 0;
}

