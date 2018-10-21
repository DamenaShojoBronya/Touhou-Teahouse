#include<stdio.h>
int main()
{
	float r, s, c;
	printf("请输入圆的半径:");
	scanf("%f", &r);
	c = 3.141592653589*r * 2 * 100;
	s = 3.141592653589*r*r * 100;
	int a = c + 0.5; printf("周长:%f\n", (float)a / 100);
	int b = s + 0.5; printf("面积:%f\n", (float)b / 100);
	return 0;
}