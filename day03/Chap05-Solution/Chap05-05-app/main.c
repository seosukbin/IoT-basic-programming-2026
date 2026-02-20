// 구구단 프로그램

#include <stdio.h>

int main() {
	int i, j;  // i => 단, j => 곱할 수

	for (i = 2; i < 10; i++) {
		printf("%d단 시작\n", i);
		printf("------------------------------>\n");
		for (j = 1; j <= 9; j++) {
			printf("%d * %d = %2d\t", i, j, i * j);
		}
		printf("\n");
	}

	return 0;
}