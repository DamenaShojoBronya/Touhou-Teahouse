/* 1006 1007 素数对猜想 （20 分）
让我们定义dn为：dn=pn+1−pn，其中p​i是第i个素数。显然有d1=1，且对于n>1有dn是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4 */

#include <iostream>
using namespace std;
int primenum_list[2] = { 0 }; int list_times = 0;

int IsThisPrimenum(long long a)
{
	for (long long i1 = 2; i1*i1 <= a; ++i1) //具体求素数的方法，从2开始除...除得整数就说明不是素数
	{
		if (a%i1 == 0) return false;
	}
	primenum_list[list_times] = a; list_times++;
	return true;
}

int main()
{
	int n = 0;
	cin >> n;//题目问小于n的素数中有多少满足“素数对猜想”
	if (n >= 100000 || n < 1) return 0;

	int primepair_times = 0;
	for (int i = 2; i <= n; i++)
	{
		if (i == 2) { primenum_list[list_times] = 2; list_times++; }  //第一个素数是2
		IsThisPrimenum(i);
		if (list_times == 2)
		{
			if ((primenum_list[1] - primenum_list[0]) == 2) primepair_times++;
			primenum_list[0] = primenum_list[1];
			list_times = 1;
		}
	}
	cout << primepair_times;

	return 0;
}