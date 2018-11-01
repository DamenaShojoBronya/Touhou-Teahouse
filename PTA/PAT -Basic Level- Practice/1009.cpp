/*	1009 说反话 （20 分）
	给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

	输入格式：
	测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

	输出格式：
	每个测试用例的输出占一行，输出倒序后的句子。

	输入样例：
	Hello World Here I Come
	输出样例：
	Come I Here World Hello */

#include <string>
#include <iostream>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	string words[81], data; char temp[81];
	char data_temp[81] = { 0 };
	int i, j = 0, num = 0, count = 0;

	getline(cin, data);

	for (i = 0; ; i++)
	{
		for (j = count; data[j] != NULL; j++)
		{
			if (count > 80) return 0;
			if (data[j] == ' ') { words[i] = data_temp; count++; break; }
			data_temp[num] = data[j]; num++;
			count++;
		}
		if (data[j] == NULL) { words[i] = data_temp; break; }
		for (int i1 = 0; i1 < 81; i1++) data_temp[i1] = 0;
		num = 0;
	}

	for (int i1 = i; i1 >= 0; i1--)
	{
		if (i1 == 0) { cout << words[i1]; break; }
		cout << words[i1] << " ";
	}

	return 0;
}
