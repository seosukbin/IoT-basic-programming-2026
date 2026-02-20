// fflush 예제 

#include <stdio.h>
#include <windows.h>

int main(void) {
	int i;
	printf("작업 진행");

	for (i = 0; i < 10; i++) {
		printf(".");
		fflush(stdout);  // 현재 버퍼에 남은 데이터를 한꺼번에 내려보낸다.
		Sleep(100); //
	}

	printf("완료!");

	return 0;
}