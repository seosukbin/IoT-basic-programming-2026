//연산자
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/int main(void)
{
	//산술 연산자
	int x, y;
	int sum, sub, mul, div, mod,inv;		
	x = 7;
	y = 3;
	sum = x + y;		//덧셈
	sub= x - y;
	mul = x * y;		//곱셈;
	div = y / x;		//나눗셈
	mod = x % y;		//나머지
	inv = -x;
	printf("x = %d, y =%d\n", x, y);
	printf("x + y= %d\n", sum);
	printf("x - y= %d\n", sub);
	printf("x * y= %d\n", mul);
	printf("x / y= %d\n", div);
	printf("x % y= %d\n", mod);
	printf("x = %d\n", inv);

	int a = 10, b = 20;
	char c = 'c';
	++a;
	--b;
	printf("a= %d\n", a);
	printf("b= %d\n", b);
	printf("a= %d\n", a++);
	


	int d = 10;
	int res;
	res = (a > b);
	printf("a>b: %d\n", a++);
	printf("a>=b: %d\n", ++a);

	//형 변환 연산자
	//int,short,char.long.float,double
	
	printf("%f\n", (float)3);
	char chval = 65;
	int ival = 0;
	ival = chval;
	printf("%d\n", ival);
	int g = 25;
	float  h = 3.1f;
	printf("int 형 변수 크기: %u\n", sizeof(g));
	printf("int형 크기: %lld\n", sizeof(h));
	//(++a,++b) a 1증가, b 1증가 후 가종 오른쪽에 있는 피연산자 값을 res에 대입해라

	//(조건)? 참의 결과: 거짓 결과;

	int i = 30, j = 25;
	printf("작은 값은 :%d\n", (i > j) ? j : i);


}