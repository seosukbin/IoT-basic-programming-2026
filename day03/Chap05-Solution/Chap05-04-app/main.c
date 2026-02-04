#include <stdio.h>
int main(void) 
{
	/*
	* 
	
	* int a = 1;
	for (i = 0; i <= 3; i++)

	{
		a *= 2;

	}
	printf("%d\n", a);
	int j;
	*/
	
	int i;
	int j;
	//이중 for문
	for(i=0; i<3; i++)
	{
		for (j=0; j<5; j++)
		{
			printf("%s", "*");
		}
		printf("\n");
	}
	return 0;
}