#include <stdio.h>

//void swap(int* pa, int* pb);
void swap(a,b);

int main(void)
{
	int a = 10, b = 20;
	//swap(&a, &b);
	swap(a, b);
	printf("a: %d, b: %d\n", a, b);

}
void swap(a,b)
{
	int temp;
	/*
	temp = *pa;
	*pa = *pb;
	*pb = temp;
	*/
	temp = a;
	a = b;
	b = temp;
}