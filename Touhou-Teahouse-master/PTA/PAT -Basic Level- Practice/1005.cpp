#include <iostream>
using namespace std;
int main()
{
	int loop_times;
	cin >> loop_times;
	if (loop_times < 1 || loop_times >= 100) return 0;
	float testnum; int un_keynum_times = 0, int_testnum;
	float test[100] = { 0 };
	float un_keynum[1000] = { 0 };
	for (int i1 = 0; i1 < loop_times; i1++)
	{
		cin >> int_testnum; test[i1] = int_testnum;
		if (test[i1] <= 1 || test[i1] > 100) return 0;
		if (i1 > 0)
		{
			for (int i = 0; i < i1; i++)
			{
				if (test[i1] == test[i]) return 0;
			}
		}
		testnum = test[i1];
		for (int i = 0;; i++)
		{
			if (testnum == 1) break;
			int b = testnum;
			if (testnum / 2 == b / 2)
			{
				testnum = testnum / 2;
				if (test[i1] != test[i1 - 1] || i1 == 0) { un_keynum[un_keynum_times] = testnum; un_keynum_times++; }
			}
			else
			{
				testnum = (3 * testnum + 1) / 2;
				if (test[i1] != test[i1 - 1] || i1 == 0) { un_keynum[un_keynum_times] = testnum; un_keynum_times++; }
			}
		}
	}
	int keynum[100] = { 0 };
	for (int i = 0; i < loop_times; i++)
	{
		for (int i1 = 0; ; i1++)
		{
			if (test[i] == un_keynum[i1]) break;
			if (un_keynum[i1] == '\0') { keynum[i] = test[i]; break; }
		}
	}
	int temp = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 99; j++)
		{
			if (keynum[i] > keynum[j])
			{
				temp = keynum[j];
				keynum[j] = keynum[i];
				keynum[i] = temp;
			}
		}
	}
	for (int i = 0; keynum[i] != 0; i++)
	{
		if (keynum[i + 1] != 0) cout << keynum[i] << " ";
		else cout << keynum[i];
	}
	return 0;
}