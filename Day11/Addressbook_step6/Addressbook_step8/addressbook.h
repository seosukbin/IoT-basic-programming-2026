#ifndef _ADDRESSBOOK_H_
#define _ADDBRESSBOOK_H_

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
#endif

#pragma region 함수선언 영역
static void print_menu(void); // 함수 선언, 이 소스내에서만 쓸거기 때문에 static 함수 선언
static int read_menu(void);

static void add_contact(void);
static void list_contacts(void);

static void search_contact(void);


static void update_contact(void);
static void delete_contact(void);

static int save_contacts(const char* filenmae); //const가 붙은 이유는 파일명이 변경 되면 안되기 때문
static int load_contacts(const char* filename);



static int find_by_phone(const char* phone); // 같은 전화 번호 중복 체크, stdlib.h에 포함 

static void sort_by_name(void); // 이름순 정렬
static int cmp_contact_name(const void* a, const void* b);

//step7

static int ab_init(void); // 주소록 초기화
static void ab_free(void); // 주소록 메모리 해제
static int ab_ensure_capacity(int need); // 용량 추가 여부 확인

#pragma endregion

