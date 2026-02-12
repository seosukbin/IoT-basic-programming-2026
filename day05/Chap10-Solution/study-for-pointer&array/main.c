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



/*
int main(void)
{
	char str[80];

	printf("문자열을 입력하세요: ");
	scanf("%s", str);
	printf("첫번째 단어: %s\n", str);
	scanf("%s", str);
	printf("두번째 단어: %s\n", str);
}

*/





//gets함수는 중간에 공백이 필요할때 사용하는 scan 함수, 그리고 gets 함수는 enter를 누르는 순간 개행 문자(\n)도 같이 저장된다
// 하지만 gets를 통해 str에 저장 될때는 널 문자로 바뀐다. 
/*
int main(void) //
{
	char str[80];
	printf("공백이 포함된 문자열 입력: ");
	gets(str);
	printf("입력한 문자열은 %s입니다. ", str);
	return 0;
}

*/

//gets함수는 기존 배열보다 큰 문자열을 받을수도 있기 때문에 위험해서
//fgets는  최대 배열의 크기 까지만 문자열을 입력 할수 있다

/*
int main(void)
{
	char str[80];
	printf("공백이 포함된 문자열 입력: ");
	fgets(str, sizeof(str), stdin); // str은 배열명이고 sizeof(str)은 배열의 크기확인,stdin은 표준 입력
	str[strlen(str) - 1] = '\0';
	printf("입력된 문자열은 %s입니다.\n", str); //fgets는 enter를 누르면 개행 문자가 포함되고 str에 저장 될때는 개행문자와 null문자가 같이 저장된다.
}

*/


/*
int main(void)
{
	int age;
	char name[20];
	printf("나이 입력: ");
	scanf("%d", &age);
	printf("이름 입력: ");
	getchar();// scanf와 getchar,gets,fgets는 버퍼를 공유 하기 때문에 scanf에서 값을 입력하면 개행를 제외하고 받아 들이기 때문에 다음 버퍼를 사용할때는 null이 먼저 들어 오기 때문에
			  // 입력이 되지 않는다. 그래서 getchar()를 사용하면 개행 문자를 사용하기 때문에 사라지므로 다음 입력이 가능하다.
	gets(name);
	printf("나이: %d, 이름: %s\n", age, name);
}
*/