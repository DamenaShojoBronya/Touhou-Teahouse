#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int PartialMatchTable(string s) {
	int r = 0;
	for (int i = 0; i <= s.length(); i++) {
		string temp(s.length(), '0');
		for (int j = 0; j < i; j++) {
			r = 0; temp[j] = s[j];
			if (j == i - 1) {
				string str(j + 1, '0');
				for (int i = 0; i < j + 1; i++) {
					if (temp[i] != '0') str[i] = temp[i];
					else break;
				}
				string* front = new string[j + 1];
				for (int i = 0; i < j + 1; i++) {
					string t2 = str;
					t2.erase(i);
					front[i] = t2;
				}
				string* rear = new string[j + 1];
				for (int i = 0; i < j + 1; i++) {
					string t2 = str;
					reverse(t2.begin(), t2.end());
					t2.erase(i);
					reverse(t2.begin(), t2.end());
					rear[i] = t2;
				}
				for (int i = 1; i < j + 1; i++) {  //i¼´³¤¶È
					if (front[i] == rear[i]) r = max(r, i);
				}
			}
		}
	}
	return r;
}

int KMP(string s, string t) {
	int x = 0, temp = 0;
	string tmp = s;
	for (int i = 0;;) {
		for (int j = 0;;) {
			if (i == s.length()) return -1;
			if (x == t.length()) return i - x;
			cout << t[j] << ":" << s[i] << endl;
			if (t[j] == s[i]) {
				x++; j++; i++; temp++;
			}
			else {
				cout << "next" << endl;
				int move = 0;
				if (x > 0) {
					if (i < tmp.length()) tmp.erase(i);
					reverse(tmp.begin(), tmp.end());
					tmp.erase(x);
					reverse(tmp.begin(), tmp.end());
					move = x - PartialMatchTable(tmp);
					tmp = s;
					i += move - 1;
				}
				x = 0; j = 0;
				++i -= temp; temp = 0;
			}
		}
	}
}

int main()
{
	string s = "bbc abcdab abc", t = "abcdab";

	if (KMP(s, t) == -1) cout << endl << "no" << endl;
	else cout << endl << KMP(s, t) << endl;

	return 0;
}