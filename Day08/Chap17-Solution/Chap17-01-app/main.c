//구조체

#include <stdio.h>

struct student
{

	char ch1; //1
	short num; //2
	char ch2; //1
	int score; //4
	char ch3; //1
	double grade; // 8byte
};

int main(void)
{
	struct student st1;
	printf("구조체 student 크기: %zu\n", sizeof(st1)); // 실제 사용되는 바이트는 12byte이지만 패딩 바이트로 16byte로 구성
}