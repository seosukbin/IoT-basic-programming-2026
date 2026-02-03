#include <stdio.h>
int main(void)
{
	int res;
	if (sizeof(short) > sizeof(long))
	{
		res = 1;
		printf("short\n");
	}
	else
		res = 0;
	printf("long\n");
	return 0;
		
}