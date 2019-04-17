#include<string>
#include<iostream>
using namespace std;

int main()
{
	string str;

	while (getline(cin, str)) {
		char word[81] = { 0 }; int a = 0;
		if (str == "THE END.") break;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'A'&&str[i] <= 'Z') word[a++] = str[i] + 'a' - 'A';
			if (str[i] >= 'a'&&str[i] <= 'z') word[a++] = str[i];
		}

		int n;
		for (int i = 0; i < 81; i++) {
			if (word[i] == 0) { n = i; break; }
		}
		//cout << n;
		if (n % 2 != 0) {
			n /= 2;
			for (int i = 1; i <= n; i++) {
				if (word[n + i] != word[n - i]) { cout << "No" << endl; goto quit; }
			}
			cout << "Yes" << endl;
		}
		else {
			n /= 2;
			for (int i = n - 1; i >= 0; i--) {
				if (word[i] != word[n++]) { cout << "No" << endl; goto quit; }
			}
			cout << "Yes" << endl;
		}
	quit: continue;
	}

	return 0;
}