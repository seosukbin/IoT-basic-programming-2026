#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int a = 0;
	while (a < 10)
	{
		a = a * 2;
		a++;
	}
	printf("a: %d\n", a);


	a = 0;
	while(a<5)
		{
		printf("%d\n", a++);

		}
	printf("\n");

	a = 0;
	do
	{
		printf("%5d", a++);
	} while (a < 5);
	printf("%d\n", a);

	a = 0;
	do {
		printf("do~ while실행\n");
		a--;
	} while (a > 0);
	printf("do~while 종료\n");
	return 0;

}