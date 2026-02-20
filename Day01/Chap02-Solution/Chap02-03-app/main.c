// 진법 표시
#include <stdio.h>
#include <limits.h>     // 각 타입별 최대,최소값 저장하는 헤더파일

int main() {
	printf("int의 최소값 : %d\n", INT_MIN);
	printf("int의 최대값 : %d\n", INT_MAX);
	printf("llong의 최대값 : %lld\n", LLONG_MAX);

	printf("%d\n", 12);   // 10진수 12
	printf("%d\n", 014);  // 8진수(숫자앞에 0) 12
	printf("%d\n", 0xC);  // 16진수(숫자앞에 0x) 12

	printf("%d\n", 12);   // 10진수
	printf("%o\n", 12);   // 12를 8진수로 출력
	printf("%x\n", 12);   // 12를 16진수로 출력
	printf("%X\n", 12);   // 12를 16진수로 출력

	// 지수표현
	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);

	// 문자, 문자열...
	// C에서는 문자 != 문자열
	printf("%c\n", 'A');
	printf("%s\n", "A");
	printf("%d\n", 'A');
	// 문자는 무조건 변환문자 %c 사용.
	// 문자열은 무조건 변환문자 %s 사용
	printf("%c는 %s 입니다.\n", '1', "first");


}