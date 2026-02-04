#include <stdio.h>

int main(void)
{
	int a = 10, b = 0;
	if (a >= 10)
	{
		b = a;
	}
	else
		b = 1000;

	if (a > 0)
	{
		b = 0;
	}
	else if (a == 0)
	{
		b = 2;

	}
	else
	{
		b = 0;
	}

	printf("a: %d, b: %d\n", a, b);

	int age = 20;
	int gender = 1;
	if (age > 12)
	{
		if (gender == 1)
		
			printf("남탕, 성인 20000원입니다\n");
		
		else
		
			printf("여탕, 성인 20000원입니다\n");

	}



	return 0;
}