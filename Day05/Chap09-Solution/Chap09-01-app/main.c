// 포인터 계속

#include <stdio.h>

// &(ampersand 또는 and), *(asterik또는 star)
int main(void) {
	int a = 10, b = 15, total;  // 변수 선언 및 초기화 a, b만
	double avg; // 평균

	// 포인터변수
	int* pa, * pb;
	int* pt = &total;    // 선언과 동시에 초기화
	double* pg = &avg;   // 선언과 동시에 초기화

	pa = &a;
	// *pa = *&a = a
	pb = &b;

	// 원래는 total = a + b; avg = total / 2.0;
	// 대신 포인터변수로 위의 작업을 대체
	// *pa -> a변수의 주소가 가지고 있는 값
	// pa -> a변수의 주소
	*pt = *pa + *pb; // total = a + b 와 동일
	*pg = *pt / 2.0; // avg = total / 2.0과 동일

	// 결과 출력
	printf("a = %d, b = %d, total = %d, avg = %.2f\n", a, b, total, avg);
	printf("*pa = %d, *pb = %d, *pt = %d, *pg = %.2f\n", *pa, *pb, *pt, *pg);

	return 0;
}