//배열
#include <stdio.h>
int main(void)
{
	//int kor, math, eng, social, science;
	int ary[5] = {90,85,70,95,100};
	int i;
	int total=0;
	double avg = 0.0;
	printf("국어 점수: %d\n", ary[0]);
	printf("수학 점수: %d\n", ary[1]);
	printf("과학 점수: %d\n", ary[2]);
	printf("사회 점수: %d\n", ary[3]);
	printf("영어 점수: %d\n", ary[4]);

	for( i=0; i<5; i++)
		total += ary[i];
	avg = total / 5;
	printf("총점: %d\n", total);
	printf("평균: %.1f\n", avg);
	return 0;

}