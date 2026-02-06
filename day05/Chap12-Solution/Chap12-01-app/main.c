#include <stdio.h>
int main(void)
{
	printf("%s\n", "apple");

	printf("%u\n", "apple"); // 문자열 주소 확인
	printf("두번쨰 문자열 주소: %u\n", "apple" + 1);
	printf("%c\n", *("apple" +1));

	return 0;
}