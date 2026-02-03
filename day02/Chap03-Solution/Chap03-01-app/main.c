#include <stdio.h>
#include <limits.h>
int main(void)
{
	int a,b,c ; // 소숫점이 없는 숫자 데이터
	float f; // 소숫점이 있는 숫자 데이터	
	double d; // 더 정밀한 소숫점이 있는 숫자 데이터
	char ch; // 문자 데이터
	a = 10;
	b = a;
	c = a + 20;
	printf("%d\n",a);
	printf("%d\n", b);
	printf("%d\n", c);
	/*정수형
	char: 크기 1byte
	short: 2byte
	int: 4byte
	long: 4byte
	long long: 8byte
	unsigned 양수로만 표현 하는 방법
	*/
	printf("변수 사이즈\n");
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
	return 0;
}