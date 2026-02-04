//switch ~case문
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	int rank = 0, money = 0;
	printf("등수를 입력 하세요\n");
	scanf_s("%d", &rank);

	/*
	switch (rank)
	{
	case 1:
		money = 300;
		break;

	case 2:
		money = 200;
		break;
	case 3:
		money = 100;
		break;
	default:
		money = 0;

	}
	*/

	if (rank == 1)

		money = 300;

	else if (rank == 2)
		money = 200;

	else if (rank == 3)
		money = 100;

	else
		money = 0;

	printf("상금: %d\n", money);

	return 0;
}