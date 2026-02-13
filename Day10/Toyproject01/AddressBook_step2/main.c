//주소록 프로그램 step2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTACTS 100
#define NAME_LEN	 31
#define PHONE_LEN	 21
#define EMAIL_LEN	 65
#define ADDR_LEN	 129
#define MEMO_LEN	 129

typedef struct _contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	char address[ADDR_LEN];
	char email[EMAIL_LEN];
	char memo[MEMO_LEN];

}Contact; // 이후contact이름으로 사용

// 변수 선언
static Contact contacts[MAX_CONTACTS];
static int count = 0;



static void print_menu(void); // 함수 선언, 이 소스내에서만 쓸거기 때문에 static 함수 선언
static int read_menu(void);
static void read_line(char* buf, int size);

static void add_contact(void);
static void list_contacts(void);



int main(void)
{
	int choice = 0;
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
			puts("[SEARCH]연락처 검색(다음 스텝에서)");
			break;

		case 4:
			puts("[EDIT]연락처 수정(다음 스텝에서)");
			break;

		case 5:
			puts("[DELETE]연락처 삭제(다음 스텝에서)");
			break;

		case 6:
			puts("프로그램 종료(다음 스텝에서)");
			return 0;

		default:
			puts("메뉴는 1~6사이 입니다.(다음 스텝에서)");
			break;


		}

		puts(" ");
	}

	return 0;
}

static void print_menu(void)
{
	puts("========================================");
	puts("                주소록프로그램(Step 2)");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색(미구현)");
	puts("4. 수정(미구현)");
	puts("5. 삭제(미구현)");
	puts("6. 종료(미구현)");
	puts("---------------------------------------");


}

static int read_menu(void)
{
	int choice, ch;
	printf("선택 >  ");
	if (scanf("%d", &choice) != 1)
	{
		while((ch= getchar())!= '\n' && ch != EOF) {}
		return -1; // 
	}
	while((ch = getchar()) != '\n' && ch != EOF){}

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

static void add_contact(void)
{
	if (count >= MAX_CONTACTS)
	{
		puts("주소록 최대인원이 100명에 도달 했습니다");
		return;
	}

	puts("[ADD] 새 연락처 입력");
	printf("이름(최대 10자): ");
	read_line(contacts[count].name, NAME_LEN); //contacts[count].name은 contacts구조체 배열에서 count번째 요소의 name 멤버에 접근해라는 표현이다. 
	printf("전화: ");
	read_line(contacts[count].phone,PHONE_LEN);
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
	printf("%4s | %10s | %17s | %30s | %20s\n","순번","이름","번호","주소","이메일");
	puts("--------------------------------------------------------------------------------");
	//printf("연락처 갯수: %d\n", count);

	//contacts 배열에 있는 주소록 출력
	for (i = 0; i < count; i++)
	{
		printf("%4d | %10s | %15s | %30s | %20s\n",i+1,contacts[i].name,contacts[i].phone, contacts[i].address, contacts[i].email);

	}
	puts("--------------------------------------------------------------------------------");

}  // 