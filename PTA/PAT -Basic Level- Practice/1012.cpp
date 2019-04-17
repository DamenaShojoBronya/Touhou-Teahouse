/*	1012 数字分类 （20 分）
	给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：
	A1 = 能被 5 整除的数字中所有偶数的和；
	A​2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1−n2+n3−n4⋯；
	A3 = 被 5 除后余 2 的数字的个数；
	A4 = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
	A5 = 被 5 除后余 4 的数字中最大数字。

	输入格式：
	每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。
	输出格式：
	对给定的 N 个正整数，按题目要求计算 A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
	若其中某一类数字不存在，则在相应位置输出 N。

	输入样例 1：
	13 1 2 3 4 5 6 7 8 9 10 20 16 18
	输出样例 1：
	30 11 2 9.7 9
	输入样例 2：
	8 1 2 4 5 6 7 9 16
	输出样例 2：
	N 11 2 N 9  */

#include <cstdio>

int main()
{
	int n = 0, a = 0, z = 0, count = 0, output[6] = { 0 };
	float b = 0;
	scanf("%d", &n);

	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a);
		if (a % 5 == 0 && a % 2 == 0)  output[1] = output[1] + a;
		if (a % 5 == 1){
			if (z == 0) { 
				output[2] = output[2] + a; z = 1; 
			}
			else {
				output[2] = output[2] - a; z = 0; 
			}
			if (i == n-1 && output[2] == 0) output[2] = -1000;
		}
		if (a % 5 == 2) output[3]++;
		if (a % 5 == 3){
			count++; b = b + a;
			output[4] = b;
		}
		if (a % 5 == 4 && a > output[5]) output[5] = a;
		if (i == n - 1)
			for (int i1 = 1; i1 < 6; i1++){
				if (output[i1] == 0) printf("N");
				else{
					if (output[2] == -1000) printf("0");
					else{
						if (i1 == 4) printf("%.1f", b / count);
						else printf("%d", output[i1]);
					}
				}
				if (i1 != 5) printf(" ");
			}
	}

	return 0;
}
