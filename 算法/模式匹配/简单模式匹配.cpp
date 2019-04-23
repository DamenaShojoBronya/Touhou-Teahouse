#include <string>
#include <iostream>
using namespace std;

int modeMatch(string s, string t) { //·µ»ØÎ»ÖÃ
	cout << s << endl << t << endl;
	cout << s.length() << endl << t.length() << endl;
	int x = 0; int temp = 0;

	for (int i = 0;;) {
		for (int j = 0;;) {
			if (i == s.length()) return -1;
			if (x == t.length()) return i - x;
			cout << t[j] << ":" << s[i] << endl;
			if (t[j] == s[i]) {
				x++; j++; i++; temp++;
			}
			else {
				cout << "next" << " ";
				j = 0; x = 0;
				++i -= temp; temp = 0;
			}
		}
	}
}

int main()
{
	string s = "bbc abcdab abc", t = "abcdab";

	if (modeMatch(s, t) == -1) cout << "no" << endl;
	else cout << endl << modeMatch(s, t);

	return 0;
}

