#include <stdio.h>

// 포인터는 가리키는 변수의 형태가 같아야 한다.

int main(void)
{
	/*
	* int a;
	int *pa;
	pa = &a;
	*pa = 10;
	printf("%d\n", pa);
	printf("%d\n", a);
	printf("%d\n", *pa);
	*/

	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb;
	int* pt = &total;
	double* pg = &avg;

	pa = &a;
	pb = &b;
	*pt = *pa + *pb;
	*pg = *pt /2.0;
	printf("%d, %d \n", *pa, *pb);
	printf("%d\n", total);
	printf("%d\n", avg);
	printf("%d, %d\n", pt, pg);
	
}

