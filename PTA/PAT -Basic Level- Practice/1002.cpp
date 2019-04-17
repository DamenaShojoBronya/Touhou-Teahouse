/* 1002 д������� ��20 �֣�

����һ�������� n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

�����ʽ��
ÿ������������� 1 ��������������������Ȼ�� n ��ֵ�����ﱣ֤ n С�� 10^100��

�����ʽ��
��һ������� n �ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ��� 1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�

����������
1234567890987654321123456789

���������
yi san wu */

#include<iostream>
#include <stdlib.h>
using namespace std;

void pinyin(int i)
{
	switch (i)
	{
	case 0:cout << "ling"; break;
	case 1:cout << "yi"; break;
	case 2:cout << "er"; break;
	case 3:cout << "san"; break;
	case 4:cout << "si"; break;
	case 5:cout << "wu"; break;
	case 6:cout << "liu"; break;
	case 7:cout << "qi"; break;
	case 8:cout << "ba"; break;
	case 9:cout << "jiu"; break;
	}
}

int main()
{
	char *a = new char[100000];
	long n = 0;
	cin >> a;

	for (int b = 0; a[b] != '\0'; b++) {
		if ((int)a[b] < 48 || (int)a[b]>57) return 0;
		a[b] = a[b] - '0';
		n = n + a[b];
	}

	int x, y = 1, size, n2 = n; float n1 = n;
	for (int i1 = 0;; i1++) {
		if (n2 > 10) n2 = n2 / 10;
		else { size = i1 + 1; break; }
	}

	int *print = new int[size];
	for (;; y++) {
		if (n > 10) {
			print[y] = n1 - n / 10 * 10;
			n = n / 10; n1 = n;
		}
		else { print[y] = n; break; }
	}
	for (; y > 0; y--) {
		pinyin(print[y]);
		if (y > 1) cout << " ";
	}

	return 0;
}

