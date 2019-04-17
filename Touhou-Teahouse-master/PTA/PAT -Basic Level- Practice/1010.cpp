/*	1010 一元多项式求导 （25 分）
	设计函数求一元多项式的导数。（注：x^​n（n为整数）的一阶导数为nx^n−1。）

	输入格式:
	以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。
	输出格式:
	以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

	输入样例:
	3 4 -5 2 6 1 -2 0
	输出样例:
	12 3 -10 1 6 0  */

#include"stdio.h"
#include <iostream>
using namespace std;

int main()
{
	int i, n[1000];
	for (i = 0; ; i++) {
		cin >> n[i];
		char a; scanf("%c", &a);
		if (a == '\n') break;
	}
	for (int i1 = 0; i1 <= i; i1 += 2) {
		if (i1 == 0 && n[i1 + 1] == 0) { cout << "0 0"; return 0; }
		if (i1 != 0) cout << " ";
		cout << n[i1] * n[i1 + 1] << " " << n[i1 + 1] - 1;
		if (n[i1 + 3] <= 0) return 0;
	}

	return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
	int x, n, flag = 0;
	while (cin >> x >> n) {
		if (n != 0) {
			if (flag == 1) cout << " ";
			cout << x*n << " " << n-1;
			flag = 1;
		}
	}
	if (flag == 0) cout << "0 0";

	return 0;
}
