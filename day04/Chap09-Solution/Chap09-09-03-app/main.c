#include <stdio.h>
int main(void)
{
	char ch;
	int in;
	double db;
	char* pch = &ch;
	int* pin = &in;
	double* pdb = &db;
	printf("char형 변수 주소 크기: %zu bytes\n", sizeof(&ch));
	printf("int형 변수 주소 크기: %zu bytes\n", sizeof(&in));
	printf("double형 변수 주소 크기: %zu bytes\n", sizeof(&db));
	//포인터 크기 -> 변수의 주소를 담아야 하기에 모두 8byte이다

	printf("char형 변수 주소 크기: %zu bytes\n", sizeof(pch));
	printf("int형 변수 주소 크기: %zu bytes\n", sizeof(pin));
	printf("double형 변수 주소 크기: %zu bytes\n", sizeof(pdb));

	// 포인터가 가르키는 변수의 크기

	printf("char형이 가르키는 변수 주소 크기: %zu bytes\n", sizeof(ch));
	printf("int형이 가르키는 변수 주소 크기: %zu bytes\n", sizeof(in));
	printf("double형이 가르키는 변수 주소 크기: %zu bytes\n", sizeof(db));


	return 0;

}