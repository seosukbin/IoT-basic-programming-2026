#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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
/*
int main(void)
{
	char str[80] = "apple juice";
	char* ps = "banana";
	puts(str); // puts는 가로 안에 있는 값을 출력 하고 자동 줄 바꿈이고 fputs는(적을값,stdout) 문자열 출력하고 줄 바꿈 없음
	fputs(ps, stdout);
	puts("milk");
}

*/

/*
int main(void)
{
	int i = 0;
	char str[20];
	char ch;

	do
	{
		ch = getchar();
		str[i] = ch;
		i++;

	}
	while (ch != '\n');

	str[--i] = '\0';

}


*/



// 문자열을 대입하는 strcpy 함수

/*
int main(void)
{
	char str1[20] = "strawberry";
	char str2[20] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;
	printf("최종 문자열: %s\n", str1);
	strcpy(str1, str2); //strcpy(복사 받을곳,복사 할 내용)
	printf("바뀐 문자열: %s\n", str1);

	strcpy(str1, ps1);
	printf("바뀐 문자열: %s\n", str1);

	strcpy(str1, ps2);
	printf("바뀐 문자열: %s\n", str1);

	strcpy(str1, "banana");
	printf("바뀐 문자열: %s\n", str1);

}
*/

//strncpy(str, "apple-pie", 5); //strncpy(복사 받을 배열,복사할 내용, 복사할 문자 수)
/*
int main(void)
{
	char str[20] = "mango tree";
	strncpy(str, "apple-pie", 5);
	//str[5] = '\0'; 이건 str이 apple만 출력 하기 위해서 이렇게 한다.
	printf("%s\n", str);


}
*/
/*
int main(void)
{
	char str[80] = "straw";

	strcat(str, "berry"); // strcat는 문자열을 이어 붙이고
	printf("%s\n", str);
	strncat(str, "piece", 3);// strncat는 문자열을 이어 붙이지만 정해진 갯수 만큼만 이어 붙인다.

	printf("%s\n", str);
	return 0;
}
*/

//문자열 길이를 계산 하는 함수
/*
int main(void)
{
	char str1[80], str2[80];
	char* resp;
	printf("2개의 과일 입력: ");
	scanf("%s%s", str1, str2);
	if (strlen(str1) > strlen(str2))
		resp = str1;
	else
		resp = str2;
	printf("이름이 긴 과일 이름: %s\n", resp);

}

*/
// 문자열을 비교하는 strcmp,strncmp strcmp 함수는 두 문자열의 사전 순서를 판단해 그 결과를 반환한다.

int main(void)
{
	char str1[80] = "pear";
	char str2[80] = "peach";

	printf("사전에 나중에 나오는 과일 이름:" );
	if (strcmp(str1, str2) > 0)
		printf("%s\n", str1);
	else
		printf("%s\n", str2);


}