//배열은 자료형이 같은 변수를 메모리에 연속으로 할당한다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
int main(void)
{
	int ary[3];
	int i;
	*(ary + 0) = 10;
	*(ary + 1) = *(ary + 0) + 10;
	printf("세번째 배열 요소에 키보드 입력: ");
	scanf("%d", ary + 2); // ary +2 또는 &ary[2]

	for (i = 0; i < 3; i++)
	{
		printf("%5d", *(ary + i)); // %5d는 정수 자릿수를 5개로 맞추는 연산 방법이다.
		//*(ary + 0)에서 ary는 배열명이고 0은 배열 값이다. *(100)
	}

}
*/

/*
int main(void)
{
	int ary[3]; // 이건 배열 안에 3개의 방을 만들겠다
	int* pa = ary;
	int i;

	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];

	for (i = 0; i < 3; i++)
	{
		printf("%5d", pa[i]);
	}
}

*/

/*
int main(void)
{
	int ary[3];
	int* pa = ary;
	printf("%d\n",sizeof(ary));
	printf("%d\n", sizeof(*pa)); // 지금 pa는 ary의 첫번째 배열을 가리킨다는 의미이다.
}

*/

/*
int main(void)
{
	int i;
	int ary[5] = { 10 ,20 ,30,40,50 };
	int* pa = &ary;
	int* pb = pa + 3;
	printf("%d\n", *pa);
	printf("%u\n", pb);

}

*/
/*
void print_ary(int* pa);

int main(void)
{
	int ary[5] = { 10,20,30,40,50 };
	print_ary(ary);
	return 0;
}

void print_ary(int* pa)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("값: %d\n", pa[i]);
	}
}

*/

/*
void print_ary(int* pa, int size);

int main(void)
{
	int ary1[5] = { 10,20,30,40,50 };
	int ary2[7] = { 10,20,30,40,50,60,70 };

	print_ary(ary1, 5);
	printf("\n");
	print_ary(ary2, 7);
	return 0;
}

void print_ary(int* pa, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("값:%d ", pa[i]);
}

*/

/*
void input_ary(double* pa, int size);
double find_max(double* pa, int size);

int main(void)
{
	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]);
	printf("%d\n", size);
	intput(ary, size);
	max = find_max(ary, size);
	printf("배열의 최댓값: %.1f\n", max);

	return 0;
}

void input_ary(double* pa, int size)
{
	int i;

	printf("%d개의 실수 값 입력", size);
	for(i = 0; i < 5; i++)
	{
		scanf("1f", pa + i);
	}
}


*/
/*
int main(void)
{
	printf("apple이 저장된 시작 주소 값: %p\n", "apple");
	printf("두번째 주소 주소 값: %p\n", "apple" +1);
	printf("첫번째 문자: %c\n", *"apple");
	printf("두번째 문자: %c\n", *("apple"+1));
}

*/
/*
int main(void)
{
	char* dessert = "apple";

	printf("오늘 후식은 %s입니다.", dessert);
	dessert = "banana";
	printf("다음 후식은 %s입니다. ",dessert);

	while (*dessert != '\0')
	{
		putchar(*dessert);
		dessert++;
	}
	printf('\n');
}
*/
