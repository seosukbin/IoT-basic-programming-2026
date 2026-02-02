//Chap02-02-app: 탈출 문자(escape character 학습)
#include <stdio.h>
int main()
{
	
	printf("hello world!\n"); // 콘솔에 문자열을 format에 맞춰서 출력 하는 함수
	printf("12345\n");
	printf("67890\n");
	printf("wow\n"); // \n은 한줄 내린다는 의미
	printf("my\tfriend,\t josuha\n"); //\t은 콘솔에 탭 추가
	printf("my\bfriend,\b josuha\n");  //\b는 콘솔에 백스페이스 추가
	printf("bark!!\a\n"); //\a는 알람 표시 나게 한다
	printf("apartment\rlotte\n"); // \r은 뒤에 있는 글자가 맨앞으로 가서 문자가 겹치게 한다
	// %d -> demical. 정수를 문자로 출력
	// %f -> float. 실수를 문자로 출력
	//1f -> 소수점을 6자리 까지 출력
	//%.nf -> 소수점 n자리 까지 출력하고 그 뒤는 반올림 해라
	printf("%f\n", 3.146259);
	printf("%d\n", 3.146259);
	printf("%10d\n", 10); // %10d는 n의 자릿수 만큼 늘려서 출력 해라

	return 0;
}
