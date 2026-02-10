#include <stdio.h>
int main(int argc, char** argv)
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("%s\n", *(argv + 1));
	}

	if (argc < 2)
	{
		printf("mygit: 명령어가 필요함\n");
		printf("사용법: mygit<command> [options]\n");
		return 0;
	}
	if (strcmp(argv[1], "init") == 0)
	{
		printf("깃저장소 초기화");

	}
	else if (strcmp(argv[1], "commit") == 0)
	{
		if (argc >= 4 && strcmp(argv[2], "-m") == 0)
		{
			printf("커밋 메시지: '%s'\n", argv[3]);
			printf("[main abc1234]커밋 완료\n");
		}
		else {
			printf("오류!");
		}
	}
	else 
	{
		printf("mygit: 알수 없는 명령'%s\n'", argv[1]);
	}
	
	return 0;

}