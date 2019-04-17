/*	1013 数素数 （20 分）
	令 P​i 表示第 i 个素数。现任给两个正整数 M≤N≤10^4，请输出 PM 到 PN 的所有素数。

	输入格式：
	输入在一行中给出 M 和 N，其间以空格分隔。

	输出格式：
	输出从 PM 到 PN 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

	输入样例：
	5 27
	输出样例：
	11 13 17 19 23 29 31 37 41 43
	47 53 59 61 67 71 73 79 83 89
	97 101 103  */

#include <iostream>
using namespace std;

int IsPrimenum(int a){
	for (int i = 2; i*i <= a; ++i) {
		if (a%i == 0) return false;
	}
	return a;
}

int main()
{
	int p[10000], n = 0, a, b;
	cin >> a >> b;

	for (int i = 2;n<b; i++) {
		if (IsPrimenum(i) != false) {
			p[n] = IsPrimenum(i); n++;
		}
	}
	int flag1 = 0, flag2 = 0;
	if (b != 0) {
		for (int i = a - 1; i < b; ) {
			if (flag1 == 1) cout << " ";
			cout << p[i++]; flag1 = 1; flag2++;
			if (flag2 == 10) {
				cout << endl;
				flag1 = 0; flag2 = 0;
			}
		}
	}

	return 0;
}