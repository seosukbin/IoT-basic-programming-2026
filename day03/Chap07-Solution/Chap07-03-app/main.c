#include <stdio.h>

void fruit(void);
void fruit2(int);


int main(void)
{
	fruit();
	fruit2(1);
	return 0;
}
void fruit(void)
{
	printf("banana\n");
	
}

void fruit2(int count) // 반환형이 없는 경우 
{
	printf("apple\n");
	if (count == 3);
		return; // 반환값이 없다라는 의미
	fruit2(count + 1);
}
