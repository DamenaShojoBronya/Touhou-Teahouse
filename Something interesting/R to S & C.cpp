#include<stdio.h>
int main()
{
	float r, s, c;
	printf("������Բ�İ뾶:");
	scanf("%f", &r);
	c = 3.141592653589*r * 2 * 100;
	s = 3.141592653589*r*r * 100;
	int a = c + 0.5; printf("�ܳ�:%f\n", (float)a / 100);
	int b = s + 0.5; printf("���:%f\n", (float)b / 100);
	return 0;
}