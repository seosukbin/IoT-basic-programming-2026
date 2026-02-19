//step7

#pragma region 헤더 함수 영역
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#pragma endregion

#pragma region 매크로 영역

#define MAX_CONTACTS 100
#define INIT_CAPACITY 10 //초기값 15로 구성
#define NAME_LEN	 31
#define PHONE_LEN	 21
#define EMAIL_LEN	 65
#define ADDR_LEN	 129
#define MEMO_LEN	 129

#pragma endregion


#pragma region 매크로 함수 영역
typedef struct _contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	char address[ADDR_LEN];
	char email[EMAIL_LEN];
	char memo[MEMO_LEN];

}Contact; // 이후contact이름으로 사용
#pragma endregion 

// 변수 선언
//static Contact contacts[MAX_CONTACTS];
static Contact* contacts = NULL;
static int count = 0;
static int capacity = 0;


#pragma region 함수선언 영역
static void print_menu(void); // 함수 선언, 이 소스내에서만 쓸거기 때문에 static 함수 선언
static int read_menu(void);
static void read_line(char* buf, int size);

static void add_contact(void);
static void list_contacts(void);

static void search_contact(void);
static void print_contact(int index);

static void update_contact(void);
static void delete_contact(void);

static int save_contacts(const char* filenmae); //const가 붙은 이유는 파일명이 변경 되면 안되기 때문
static int load_contacts(const char* filename);
static void trim_newline(char* s); // 줄바꿈 제거 기능 추가

static int contains_pipe(const char* s); // 입력 문자열 중에 |존재 확인
static int find_by_phone(const char* phone); // 같은 전화 번호 중복 체크, stdlib.h에 포함 

static void sort_by_name(void); // 이름순 정렬
static int cmp_contact_name(const void* a, const void* b);

//step7

static int ab_init(void); // 주소록 초기화
static void ab_free(void); // 주소록 메모리 해제
static int ab_ensure_capacity(int need); // 용량 추가 여부 확인

#pragma endregion


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

static void print_menu(void)
{
	puts("========================================");
	puts("                주소록프로그램(Step 6)");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색");
	puts("4. 수정");
	puts("5. 삭제");
	puts("6. 데이터 정렬");
	puts("7. 종료");
	/*puts("7. 저장");
	puts("8. 로드");*/
	puts("---------------------------------------");


}


static int read_menu(void)
{
	int choice, ch;
	printf("선택 >  ");
	if (scanf("%d", &choice) != 1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		return -1; // 
	}
	while ((ch = getchar()) != '\n' && ch != EOF) {}

	return choice;

}


//fgets로 입력 할때 문제가 발생 하지 않도록, 문자열 끝에 \n 제거
static void read_line(char* buf, int size)
{
	if (fgets(buf, size, stdin) == NULL)
	{
		buf[0] = '\0';
		return;
	}
	// strcspn(buf,"\n") = 버퍼 문자열 내에서 \n을 찾아서 그 위치 값을 return한다.
	// 여기서 \buf는 buf의 문자열 값이다. 
	buf[strcspn(buf, "\n")] = '\0'; // 문자열 끝 \n을 \0으로 변경
}


static void trim_newline(char* s)
{
	s[strcspn(s, "\n")] = '\0'; // 문자열 마지막에 엔터가 있으면 제거 하는 함수
}
static void add_contact(void)
{
	if (count >= MAX_CONTACTS)
	{
		puts("주소록 최대인원이 100명에 도달 했습니다");
		return;
	}

	puts("[ADD] 새 연락처 입력");
	printf("이름: ");
	read_line(contacts[count].name, NAME_LEN); //contacts[count].name은 contacts구조체 배열에서 count번째 요소의 name 멤버에 접근해라는 표현이다. 
	if (contains_pipe(contacts[count].name))
	{
		puts("'|'문자는 사용 할수 없습니다. 다시 추가 하세요.");
		return;
	}
	printf("전화: ");
	read_line(contacts[count].phone, PHONE_LEN);
	
	if (strlen(contacts[count].phone) == 0)
	{
		puts("전화 번호는 필수 입니다.");
		return;
		
	}
	int dup = find_by_phone(contacts[count].phone);
	if (dup != -1)
	{
		printf("동일 전화 번호 존재(NO: %3d, 이름: %10s)\n", dup, contacts[dup].name);
	}

	printf("주소: ");
	read_line(contacts[count].address, ADDR_LEN);
	printf("이메일: ");
	read_line(contacts[count].email, EMAIL_LEN);
	printf("메모: ");
	read_line(contacts[count].memo, MEMO_LEN);
	count++;
	puts("추가 완료!");
}
//메뉴 2번
static void list_contacts(void)
{
	int i;
	if (count == 0)
	{
		puts("[LIST]저장된 연락처 없음");
		return 0;
	}
	puts("[LIST]연락처 목록");
	puts("--------------------------------------------------------------------------------");
	printf("%4s | %10s | %17s | %30s | %20s\n", "순번", "이름", "번호", "주소", "이메일");
	puts("--------------------------------------------------------------------------------");
	//printf("연락처 갯수: %d\n", count);

	//contacts 배열에 있는 주소록 출력
	for (i = 0; i < count; i++)
	{
		printf("%4d | %10s | %15s | %30s | %20s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);

	}
	puts("--------------------------------------------------------------------------------");

}  // 


static int contains_pipe(const char* s)
{
	return (strchr(s, '|') != NULL);
}

static int cmp_contact_name(const void* a, const void* b)
{
	const Contact* ca = (const Contact*)a;
	const Contact* cb = (const Contact*)b;
	return strcmp(ca->name, (*cb).name); 


}

static void sort_by_name(void)
{
	if (count <= 1)
	{
		puts("정렬 불필요!");
		return;
	}
	// 퀵소트
	qsort(contacts, count, sizeof(Contact), cmp_contact_name);
	puts("이름순 정렬 완료!");
}

static int find_by_phone(const char* phone)
{
	int i;
	for (i = 0; i < count; i++)
	{
		if (strcmp(contacts[i].phone, phone) == 0)
		{
			return i;
		}
	}
}


//static int read_menu(void)
//{
//	int choice, ch;
//	printf("선택 >");
//	if (scanf("%d", &choice) != 1)
//	{
//		while((ch = getchar()) != '\n' && ch!= EOF){}
//		return -1;
//	}
//}

//검색 함수
static void search_contact(void)
{
	char keyword[NAME_LEN];
	int found = 0;
	int i;
	if (count == 0)
	{
		puts("검색할 연락처가 없습니다.");
		return;
	}

	printf("검색할 이름 입력: ");
	read_line(keyword, NAME_LEN);

	if (strlen(keyword) == 0)
	{
		puts("검색할 이름이 없습니다. ");
		return;

	}

	puts("검색 결과: ");
	puts("---------------------------------------");

	for (i = 0; i < count; i++)
	{	//strcmp와 유사한데 strstr(찾을 문자열, 찾는 문자열) 같은 문자열이 있으면 그 문자열 리턴
		if (strstr(contacts[i].name, keyword) != NULL)
		{
			printf("순번: %d\n", i + 1);
			print_contact(i);
			puts("---------------------------------------");
			found = 1;
		}
	}

	if (found < 1)
	{
		puts("일치하는 연락처가 없습니다. ");
	}

}
// 메뉴 3-1 상세 출력 함수
static void print_contact(int index)
{
	printf("이름: %s\n", contacts[index].name);
	printf("전화: %s\n", contacts[index].address);
	printf("주소: %s\n", contacts[index].phone);
	printf("이메일: %s\n", contacts[index].email);
	printf("메모: %s\n", contacts[index].memo);

}


// 4. 주소록 수정 함수
static void update_contact(void)

{
	char buf[MEMO_LEN];
	int index, ch;
	if (count == 0)
	{
		puts("수정할 연락처가 없습니다.");
		return;
	}

	printf("수정할 번호 입력: (1~%d) >", count);
	if (scanf("%d", &index) != 1) // 1이 안나온다는것은 입력 실패
	{
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		puts("숫자 입력 요망");
		return;

	}
	while ((ch = getchar()) != '\n' && ch != EOF) {} //  \n 그리고 EOF이 없어질때 까지 초기화 한다는 의미

	if ((index < 1) || index > count)
	{
		puts("입력 범위 초과: ");
		return;

	}
	puts("현재 정보: ");
	print_contact(index - 1); // 실제 인덱스는 0,1,2이지만 실제 순번은 1,2,3을 사용 하기 때문에 -1을 사용한다
	puts("---------------------------------------");

	puts("새 값 입력(엔터만 입력하면 기존값 유지)");

	printf("이름(%s) > ", contacts[index - 1].name);
	read_line(buf, NAME_LEN);
	if (buf[0] != '\0') // 엔터만 친게 아니면
	{
		strncpy(contacts[index - 1].name, buf, NAME_LEN);
		contacts[index - 1].name[NAME_LEN - 1] = '\0'; // 글자를 max로 적으면 마지막에 꼭 \0이 들어가야 문자열 끝을 만들어 준다. 
	}

	printf("전화(%s) > ", contacts[index - 1].phone);
	read_line(buf, PHONE_LEN);
	if (buf[0] != '\0') // 엔터만 친게 아니면
	{
		strncpy(contacts[index - 1].phone, buf, PHONE_LEN);
		contacts[index - 1].phone[PHONE_LEN - 1] = '\0'; // 글자를 max로 적으면 마지막에 꼭 \0이 들어가야 문자열 끝을 만들어 준다. 
	}

	printf("주소(%s) > ", contacts[index - 1].address);
	read_line(buf, ADDR_LEN);
	if (buf[0] != '\0') // 엔터만 친게 아니면
	{
		strncpy(contacts[index - 1].address, buf, ADDR_LEN);
		contacts[index - 1].address[ADDR_LEN - 1] = '\0'; // 글자를 max로 적으면 마지막에 꼭 \0이 들어가야 문자열 끝을 만들어 준다. 
	}

	printf("이메일(%s) > ", contacts[index - 1].email);
	read_line(buf, ADDR_LEN);
	if (buf[0] != '\0') // 엔터만 친게 아니면
	{
		strncpy(contacts[index - 1].email, buf, EMAIL_LEN);
		contacts[index - 1].email[EMAIL_LEN - 1] = '\0'; // 글자를 max로 적으면 마지막에 꼭 \0이 들어가야 문자열 끝을 만들어 준다. 
	}

	printf("메모(%s) > ", contacts[index - 1].memo);
	read_line(buf, MEMO_LEN);
	if (buf[0] != '\0') // 엔터만 친게 아니면
	{
		strncpy(contacts[index - 1].memo, buf, MEMO_LEN);
		contacts[index - 1].memo[MEMO_LEN - 1] = '\0'; // 글자를 max로 적으면 마지막에 꼭 \0이 들어가야 문자열 끝을 만들어 준다. 
	}

}

// 메뉴 5. 주소 삭제 함수
static void delete_contact(void)
{
	int index, i, ch;
	char yn[8];

	if (count == 0)
	{
		puts("삭제할 번호가 없습니다.");
	}

	printf("[DELETE]할 번호 입력: (1~%d) >", count);
	if (scanf("%d", &index) != 1) // 1이 안나온다는것은 입력 실패
	{
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		puts("숫자 입력 요망");
		return;

	}
	while ((ch = getchar()) != '\n' && ch != EOF) {} //  \n 그리고 EOF이 없어질때 까지 초기화 한다는 의미

	if ((index < 1) || index > count)
	{
		puts("입력 범위 초과: ");
		return;

	}
	puts("삭제할 정보: ");
	print_contact(index - 1);
	//여기 까지가 1차 작성


	printf("정말 삭제 하시겠습니까? (y/n) >");
	read_line(yn, (int)sizeof(yn));

	if (!(yn[0] == 'y' || yn[0] == 'Y'))
	{
		puts("삭제 취소 합니다.");
		return;
	}

	//현재 삭제 할 값 이후의 배열 요소를 앞으로 당긴다.

	for (i = index - 1; i < count - 1; i++)
	{
		contacts[i] = contacts[i + 1]; // 전부 앞으로 당긴다.
		count--; // 한건 지웠으니 전체 수를 1감소
	}
	puts("삭제 완료!");


}


// 메뉴 7. 저장 함수
static int save_contacts(const char* filenmae)
{
	FILE* fp = fopen(filenmae, "w");
	int i;

	if (!fp) // fp == NULL
	{
		puts("파일 저장 실패(경로나 권한 확인 요망");
		return 0;
	}
	// 저장 작업
	for (i = 0; i < count; i++)
	{
		//구분자 | 사용
		fprintf(fp, "%s|%s|%s|%s|%s\n", contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email, contacts[i].memo);
	}

	fclose(fp);
	puts("저장 완료!");
	return 1;
	// 한건 성공

}

static int load_contacts(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	char  line[600];
	if (!fp)
	{
		puts("불러올 파일이 없습니다.");
		return 0;


	}
	count = 0;
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		char* name;
		char* phone;
		char* address;
		char* email;
		char* memo;

		trim_newline(line); // 메모 이후 \n을 삭제

		//|로 값들 각각 분리
		name = strtok(line, "|");
		phone = strtok(NULL, "|");
		address = strtok(NULL, "|");
		email = strtok(NULL, "|");
		memo = strtok(NULL, "|");

		if (!name || !phone || !email || !memo || !address) continue;

		if (count >= MAX_CONTACTS) break;

		strncpy(contacts[count].name, name, NAME_LEN);
		contacts[count].name[NAME_LEN - 1] = '\0';

		strncpy(contacts[count].phone, phone, PHONE_LEN);
		contacts[count].phone[PHONE_LEN - 1] = '\0';

		strncpy(contacts[count].address, address, ADDR_LEN);
		contacts[count].address[ADDR_LEN - 1] = '\0';

		strncpy(contacts[count].email, email, EMAIL_LEN);
		contacts[count].email[EMAIL_LEN - 1] = '\0';

		strncpy(contacts[count].memo, memo, MEMO_LEN);
		contacts[count].memo[MEMO_LEN - 1] = '\0';

		count++;
	}
	fclose(fp);
	puts("불러오기 완료!");
	return 1;
}

static int ab_init(void)
{
	capacity = INIT_CAPACITY;
	count = 0;
	contacts = (Contact*)malloc(sizeof(Contact) * capacity);
	if (!contacts)
	{
		puts("메모리 할당 실패!");
		return 0;
	}
	return 1;


}
// 주소록 메모리 해제
static void ab_free(void)
{
	free(contacts);
	contacts = NULL; //NULL로 초기화
	count = 0;
	capacity = 0;

}
// 주소록 크기가 작으면 동적으로 늘리는 함수
static int ab_ensure_capacity(int need)
{
	Contact* newbuf;
	int newcap;
	if (need <= capacity)return 1;

	newcap = capacity;
	while (newcap < need)
	{
		newcap = newcap * 2;

	}
	
	newbuf = (Contact*)realloc(contacts, sizeof(Contact) * newcap);
	if (!newbuf)
	{
		puts("메모리 재할당 실패(메모리 부족)!!");
		return 0;
	}
	contacts = newbuf;
	capacity = newcap;
	return;
}