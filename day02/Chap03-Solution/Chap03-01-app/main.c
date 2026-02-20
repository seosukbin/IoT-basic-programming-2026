// 변수 
#include <stdio.h> // 표준 입출력 헤더파일
#include <limits.h> // 타입의 최소,최대값 담고있는 헤더파일

int main(void) {
	// 변수 상자 만들기
	int a;  // 소수점이 없는 숫자 데이터
	int b, c;  // 변수 여러개 선언
	float f;  // 소수점이 있는 숫자 데이터
	double d;  // 더 정밀한 소수점이 있는 숫자 데이터
	char ch; // 문자 데이터

	// assignment(대입) 왼쪽의 변수에 오른쪽 값을 넣는다
	a = 10;
	b = a;
	c = a + 20;

	//c = 3.145;  // Ctrl + / -> 주석 처리

	f = 3.14159f;
	d = 3.14159265358979099;
	ch = 'A';

	// 출력
	printf("변수 a의 값 %d\n", a);
	printf("변수 b의 값 %d\n", b);
	printf("변수 c의 값 %d\n", c);
	printf("변수 f의 값 %f\n", f);  // 빨간색밑줄은 무조건 오류, 녹색 밑줄은 경고(!) 실행은 가능
	// %f는 소수점 6째 자리까지 출력한다는 변환문자
	printf("변수 d의 값 %.16f\n", d);
	printf("변수 ch의 값 %c\n", ch);
	printf("변수 ch의 값 %d\n", ch);
	printf("변수 ch의 값 %c\n", 97);

	// ASCII - 영문자, 특수문자(+.-,etc) 등 숫자값으로 1:1 매칭되어 있음
	// https://ko.wikipedia.org/wiki/ASCII 아스키표 참조

	// 정수형 
	// char : 크기 1byte -> 8bit 00000000~11111111  -> 00~FF (0~255 까지 표현) 최대크기 255	
	// short : 2bytes 
	// int(기본, 제일 중요!) : 4bytes
	// long : 4bytes
	// long long : 8bytes	
	printf("변수 char, %zu byte, 최소 %d, 최대 %d \n", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("변수 short, %zu byte, 최소 %d, 최대 %d \n", sizeof(short), SHRT_MIN, SHRT_MAX);
	printf("변수 int, %zu byte, 최소 %d, 최대 %d \n", sizeof(int), INT_MIN, INT_MAX);
	printf("변수 int, %zu byte, 최소 %lld, 최대 %lld \n", sizeof(long long), LLONG_MIN, LLONG_MAX);

	// unsigned 양수로만 표현하는 방법
	// 최소값이 0
	printf("변수 unsigned char, %zu byte, 최소 %d, 최대 %d \n", sizeof(unsigned char), 0, UCHAR_MAX);
	printf("변수 unsigned short, %zu byte, 최소 %d, 최대 %d \n", sizeof(unsigned short), 0, USHRT_MAX);
	printf("변수 unsigned int, %zu byte, 최소 %d, 최대 %u \n", sizeof(unsigned int), 0, UINT_MAX);
	printf("변수 unsigned long, %zu byte, 최소 %d, 최대 %u \n", sizeof(unsigned long), 0, ULONG_MAX);
	printf("변수 unsigned long long, %zu byte, 최소 %d, 최대 %llu \n", sizeof(unsigned long long), 0, ULLONG_MAX);
}