// 배열

#include <stdio.h>

int main() {
	//int kor, math, eng, social, science;  // 5과목 점수 저장변수

	// 배열 선언과 초기화 방법
	//int ary[5];  // 1. 배열선언 크기 5인 정수형 배열 생성  선언과 초기화 따로
	//int ary[5] = { 90, 85, 70, 95, 100 }; // 2. 배열선언과 동시에 초기화
	int ary[5] = { 0 }; // 3. 모든 배열요소를 0으로 초기화 
	int ary2[] = { 1, 2, 3, 4 }; // 4. 배열 초기화로 배열크기를 자동지정

	int tot = 0; // 5과목 총점
	double avg = 0.0;  // 평균점수
	int i = 0;

	ary[0] = 90; // 국어 점수
	ary[1] = 85; // 수학 점수
	ary[2] = 70; // 영어 점수
	ary[3] = 95; // 사회 점수
	ary[4] = 100; // 과학 점수

	printf("국어 점수 : %d\n", ary[0]);
	printf("수학 점수 : %d\n", ary[1]);
	printf("영어 점수 : %d\n", ary[2]);
	printf("사회 점수 : %d\n", ary[3]);
	printf("과학 점수 : %d\n", ary[4]);
	//printf("과학 점수 : %d\n", ary[5]);  // 오류가 아닌데 큰 문제

	// 합산
	//tot = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];	
	for (i = 0; i < 5; i++) {  // 반복문 사용하라
		tot += ary[i];
	}
	printf("총점은 %d\n", tot);

	avg = tot / 5.0;
	printf("평균은 %.1f\n", avg);

	return 0;
}