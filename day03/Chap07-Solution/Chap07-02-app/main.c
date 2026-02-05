#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int get_num(void);
void print_char(char, int); // main만 선언 안해도 되고 나머지는 맨 위에다가 선언을 해줘야 한다.
void print_line(void);


int main(void)
{
	print_line();
	printf("학번:   이름   학점\n");
	print_line();
	int result;
	print_char('@', 5);
	result = get_num();
	printf("반환값은 : %d\n", result);
	return 0;
}

void print_line(void)
{
	int i;
	for (i = 0; i < 50; i++)
		printf("-");
	printf("\n");
}// 함수를 호출한 곳으로 점프백


void print_char(char ch, int count)
{
	int i;

	for (i = 0; i < count; i++)
		printf("%c", ch);
	
	printf("\n");
}

int get_num(void)
{
	int num;
	printf("양수 입력: ");
	scanf_s("%d", &num);
	return num;

}