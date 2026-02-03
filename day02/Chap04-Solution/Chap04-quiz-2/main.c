#include <stdio.h>
int main(void)
{
	double seats = 70, audience = 65;
	double rate = (audience /seats) * 100;
	
	printf("관객수 비율: %.1f%%\n",rate);
	return 0;

}