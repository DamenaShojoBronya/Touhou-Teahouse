#include <iostream>
using namespace std;

void func(int x[], int n){
	int temp, i, j;
	int m = (n - 1) / 2;
	for (i = 0; i <= m; ++i){
		j = n - 1 - i;
		temp = x[i];
		x[i] = x[j];
		x[j] = temp;
	}


}
void func2(int*x, int n){
	int *p, *i, *j, m, temp;
	m = (n - 1) / 2;
	i = x;
	j = x + n - 1;
	p = x + m;
	for (; i <= p; ++i, j--){
		temp = *i;
		*i = *j;
		*j = temp;
	}
}

int main()                    //ʵ���βξ�������
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	func(list, 10);
	return 0;
}

int main()                 //ʵ�������飬�β���ָ��
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	func2(list, 10);
	return 0;

}

int main()                //ʵ���βξ���ָ��
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = list;
	p = list;
	func2(p, 10);

}

int main()                //ʵ����ָ�� �β�������
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = list;
	p = list;
	func(p, 10);
}