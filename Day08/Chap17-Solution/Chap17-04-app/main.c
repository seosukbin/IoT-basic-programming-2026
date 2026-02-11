// 구조체 포인터 -> 연산자

#include <stdio.h>

struct score
{
	int kor;
	int eng;
	int math;
};

struct address
{
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

void print_list(struct address*);

int main(void)
{
	struct score yuni = { .kor = 90, .eng = 80, .math = 70 };
	struct score* ps = &yuni;
	printf("국어: %d\n", (*ps).kor);
	printf("영어: %d\n", (*ps).eng);
	printf("수학: %d\n", ps->math);
	// struct address 구조체 배열
	struct address list[5] =
	{
		{"홍길동",23,"111-1111","울릉도 독도"},
		{"이순신",35,"222-2222","서울 건천동"},
		{"장보고",19,"333-3333","완도 청해진"},
		{"유관순",15,"444-4444","충남 천안"},
		{"안중근",45,"555-5555","황해도 해주"},
	};
	int i;
	printf("main 함수 출력\n");
	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n", list[i].name,list[i].age, list[i].tel, list[i].addr);
	}
	printf("print_list 함수 출력 \n");
	print_list(list);


}


void print_list(struct address* lp)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n",(*(lp+i)).name,(lp+i)->age, (lp + i)->tel,(lp+i)->addr);

	}

}