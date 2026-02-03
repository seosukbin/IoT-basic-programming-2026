#include <stdio.h>

int main(void)
{
	double height, weight, bmi;
	printf("키와 몸무게를 입력 하세요: \n");
	printf("키: ");
	scanf_s("%lf",&height);
	printf("몸무게: ");
	scanf_s("%lf",&weight);
	bmi = weight / (height);
	if (2 <= bmi)
		printf("정상 체중입니다");

	else
		printf("관리가 필요합니다.");
	return 0;

	

}