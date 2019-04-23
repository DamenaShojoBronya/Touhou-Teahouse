#include <iostream>
using namespace std;

int strlen(char* str) {
	for (int i = 0;; i++) {
		if (str[i] == NULL) return i;
	}
}

int strFind(char* s, char* t) { //·µ»ØÎ»ÖÃ
	cout << s << " " << strlen(s) << endl;
	cout << t << " " << strlen(t) << endl;
	int x = 0; int temp = 0;

	for (int i = 0;;) {
		for (int j = 0;;) {
			if (i == strlen(s)) return -1;
			if (x == strlen(t)) return i - x;
			if (t[j] == s[i]) {
				x++; j++; i++; temp++;
			}
			else {
				j = 0; x = 0;
				++i -= temp; temp = 0;
			}
		}
	}
}

int main()
{
	char* s = "bbc abcdab abc"; char* t = "abcdab";
	cout << strFind(s, t);
	return 0;
}