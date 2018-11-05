	/*	1014 福尔摩斯的约会 （20 分）
	大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，
	因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头
	于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。
	现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

	输入格式：
	输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

	输出格式：
	在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解。

	输入样例：
	3485djjkxh4hhGENsNAf3485djjkxh4hhGENNNNf3485djjkxh4hhGENNNNf
	2984akDfkkkkggEdsbAp
	s&hgsfdks&hgsfdks&hgsfdk
	d&Hybcvnms&hgsfds
	输出样例：
	THU 14:04  */

#include<string>
#include <iostream>
using namespace std;

int main()
{
	string str1, str2, str3, str4; int flag = 0;
	string day[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	cin >> str1 >> str2 >> str3 >> str4;

	for (int i = 0; i < 60; i++) {
		if (str1[i] == str2[i] && flag == 1){
			if (str1[i] >= '0'&&str1[i] <= '9') {
				cout << "0" << str1[i] - '0' << ":"; break;
			}
			if (str1[i] >= 'A'&&str1[i] <= 'N') {
				cout << str1[i] - 'A' + 10 << ":"; break;
			}
		}
		if (str1[i] == str2[i] && flag == 0) {
			if (str1[i] >= 'A'&&str1[i] <= 'G') {
				cout << day[str1[i] - 'A'] << " ";
				flag = 1;
			}
		}
		if (str3[i] == str4[i]) {
			if ((str3[i] >= 'a' && str3[i] <= 'z') || str3[i] >= 'A' && str3[i] <= 'Z') {
				if (i > 10) { cout << i; break; }
				else { cout << "0" << i; break; }
			}
		}
	}

	return 0;
}
