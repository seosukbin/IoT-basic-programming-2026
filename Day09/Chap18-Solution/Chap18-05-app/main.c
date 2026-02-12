#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void)
{
	FILE* tfp, * bfp;
	int num = 97;
	int res;
	tfp = fopen("text.txt", "wt");
	fprintf(tfp, "%d", num);
	bfp = fopen("binary.dat", "wb");
	fwrite(&num, sizeof(num), 1, bfp); //만약 배열이면 fwrite(arr,sizeof(arr[0]),배열요소 개수,fp);
	fclose(tfp);
	fclose(bfp);

	bfp = fopen("./binary.dat", "rb");
	fread(&res, sizeof(res), 1, bfp);
	printf("%d", res);
	
	fclose(bfp);

	printf("처리 완료");
	return 0;
}