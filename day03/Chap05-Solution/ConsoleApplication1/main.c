#include <stdio.h>
int main(void)
{
	int i;
	/*
	int sum = 0;
	for (i = 1; i <= 10; i++)
	{
		sum += i;
		if (i >= 30)
			break;
	}
	printf("모든 sum의 값: %d\n", sum);
	*/
	

	// 특정 상황에서 반복문을 일부 반복문을 제외 시킬떄 사용한다.
	for (i = 1; i <= 100; i++)
		if (i % 3 == 0)
		{
			continue;
		}
		else
			printf("%d\t", i);
		
	   
} 