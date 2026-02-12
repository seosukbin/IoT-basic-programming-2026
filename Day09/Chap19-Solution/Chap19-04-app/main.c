// 헤더파일.h

#include <stdio.h>
#include "line.h"

int main(void)
{
	Line line1 = { .first = {10,20},.second = {100,300} };
	Point p1;
	p1.x = (line1.first.x + line1.second.x) / 2;
	p1.y = (line1.first.y + line1.second.y) / 2;
	printf("선의 가운데점 좌표: (%d,%d)\n", p1.x, p1.y);

	return 0;
}