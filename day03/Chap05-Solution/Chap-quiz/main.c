#include <stdio.h>
int main(void)
{
	/*
	*
	**
	***
	****
	*****
	*/
	int i, j;
	/*
	for (i = 1; i <= 5; i++)
	{
		for (j = 0; j <= i; j++)
			printf( "*");
		printf("\n");
	}

	*/
	/*
	* for (i = 1; i <= 5; i++)
	{
		for (k = 1; k <= 5 - i; k++)
		{
			printf(" ");
		}
		for (j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}

	*    *
	 *  *
	  *
	 *  *
	*    *
	*/
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			if (i == j || i + j == 4)
				printf("*");
			else
				printf(" ");
		printf("\n");

	}


}