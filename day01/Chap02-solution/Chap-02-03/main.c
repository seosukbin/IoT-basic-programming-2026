// 진법 표시
#include <stdio.h>
#include <limits.h> // 각 타입의 최대,최소값을 저장하는 헤더 파일이다

int main(void)
{
	printf("int의 최대값: %d\n", INT_MAX);
	printf("int의 최솟값: %d\n", INT_MIN);
	printf("%d\n",12); //10진수 12
	printf("%d\n",014); // 8진수(숫자 앞에 0)12
	printf("%d\n",0xC); // 16진수(숫자 앞에0x) 12
	printf("%o\n", 12); //12를 8진수로 표현
	printf("%X\n", 12); // 12를 16진수로 표현
	
	//지수 표현
	printf("%.1f\n", 1e6);
	// c에서는 문자와 문자열은 다르다
	printf("%c\n", 'A'); // 문자는 c로 하고 문자열은 s로 해야한다
	printf("%s\n", "A"); 
	printf("%d\n", 'A');

	return 0;

}