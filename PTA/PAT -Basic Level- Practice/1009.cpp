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