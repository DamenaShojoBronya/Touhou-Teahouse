#include<stdio.h>
int main()
{
	printf("请输入摄氏温度数值");
	float a, b;
	scanf("%f", &a);
	printf("摄氏温度为");
	b = (a - 32) * 5 / 9;
	printf("华氏温度%f", b);
	return 0;
}