#include <stdio.h>

int main(void)
{
	int a = 10, b = 15,total;

	double avg;

	int* pa, * pb;
	int* pt = &total;
	double* pg = &avg;
	pa = &a;
	pb = &b;

	* pt = *pa + *pb;

	*pg = *pt / 2.0;

	printf("a = %d, b = %d, total= %d, avg = %.2f\n", a, b, total, avg);
	printf("*pa = %d, *pb = %d, *pt= %d, *pg = %.2f\n", *pa, *pb, *pt, *pg);



	/*
	* /int a;

	int* pa; // 포인터 변수는 값은 담는것이 아닌 다른 변수의 주소를 담는다.
	pa = &a; // a의 주소를 pa에 저장한다.
	// 포인터가 가리키는 변수에다가 값을 지정한다.
	*pa = 100; 
	// 지금 위에서 a 변수의 주소를 포인터 변수에 저장이 되어 있고 pa에 100을 넣었기 때문에 a의 주소에 100을 넣었기 때문에 a에 100이 들어가 있다.
	printf("a값 출력 : %d\n", a);


	printf("변수 a의 주소: %d\n", &a);
	printf("포인터 변수 pa의 값: %u\n", pa);
*/	 