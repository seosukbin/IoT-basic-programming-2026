#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct profile
{
	char name[20];
	int age;
	double height;
	char* intro;

};

int main(void)
{
	struct profile one;

	strcpy(one.name, "홍길동");
	one.age = 19;
	one.height = 170.3;

	one.intro = (char*)malloc(80);
	printf("자기 소개 입력: ");
	gets(one.intro);
	// 다른 변수의 주소를 담거나 아니면 동적 할당으로 사이즈를 잡아야 한다. 
	printf("프로필 출력\n");
	printf("이름 : %s\n", one.name);
	printf("나이 : %d\n", one.age);
	printf("키 : %.1f\n", one.height);
	printf("자기 소개 : %s\n", one.intro);
	
	free(one.intro);
	return 0;
}