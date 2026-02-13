extern int count; //main.c에 있는 변수를 사용
extern int total; // input.c에 있는 변수를 사용

double average(void)
{
	return total / (double)count;
}