#include <stdio.h>
/*
int main(voiid)
{
	int ary[3];

	int* pa = ary;
	int i;
	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", pa[i]);
	}
}
*/

int main(void)
{
	int ary[3] = { 0 };
	int* pary = ary;
	int i = 0;
	printf("배열의 크기 : %d\n", sizeof(ary));
	printf("포인터의 크기: %d\n", sizeof(pary));

}