#include <stdio.h>
#include <float.h>

int main(void)
{
	printf("변수 float, %zu byte, 최소%e, 최대%e\n", sizeof(float), FLT_MIN, FLT_MAX);
	printf("변수 double, %zu byte, 최소%e, 최대%e\n", sizeof(float), DBL_MIN, DBL_MAX);

	char fruit[20] = "strawberry";
	printf("%s\n", fruit);
	strcpy(fruit, "banana");
	printf("%s\n", fruit);
	return 0;
}