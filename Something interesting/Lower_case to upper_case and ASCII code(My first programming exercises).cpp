﻿#include<stdio.h>
int main()
{
	int a, b, c;
	printf("请输入一个小写字母,它将被转换为对应的大写字母和ASCII码\n");
	a = getchar();
	if (a>97 && a<122)
		printf("%c,%x", b = a - 32, a);
	else
		for (c = 1; c<10; c++)
		{
			printf("******请勿输入大写字母或数字******");
		}
	return 0;
}