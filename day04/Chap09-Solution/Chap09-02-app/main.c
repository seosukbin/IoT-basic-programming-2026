#include <stdio.h>

int main(void)
{
	int a = 100;
	double b = 300;
	char c = 12;
	printf("int형 변수 a의 주소: %u\n", &a); // &는 메모리 주소를 나타내는 연산자, %u는 unsigned
	printf("double형 변수 b의 주소: %u\n", &b);
	printf("char형 변수 c의 주소: %u\n", &c);
}