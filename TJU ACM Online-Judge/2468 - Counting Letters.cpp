#include<string>
#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;

	while (n-- > 0) {
		string str; cin >> str;
		int a[26] = { 0 }, max = 0;

		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < 26; j++) {
				if (str[i] == 'a' + j) a[j]++;
				max = max > a[j] ? max : a[j];
			}
		}

		for (int i = 0; i < 26; i++) {
			if (a[i] == max) cout << (char)('a' + i);
		}
		cout << endl;
	}

	return 0;
}