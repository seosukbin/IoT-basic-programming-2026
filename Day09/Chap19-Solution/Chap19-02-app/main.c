// 분할 컴파일
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void input_data(int*, int*);
double average(int, int);

int main(void)
{
	int a, b;
	double avg;

	input_data(&a, &b);

	avg = average(a, b);
	printf("%d와 %d의 평균은 %.1f입니다.\n", a, b, avg);
	return 0;

}
