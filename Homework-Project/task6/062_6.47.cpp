/*	2. 6.6 (Display patterns) Write a function to display a pattern as follows:
1
2 1
3 2	1
…
n n-1 … 3 2 1
//The function header is
void displayPattern(int n) */

#include<iostream>
#include<iomanip>
using namespace std;

void displayPattern(int n) {
	for (int i = 0; i <= n; i++) {
		for (int i3 = n - i; i3 > 0; i3--) {
			cout << "  ";
		}
		for (int j = i; j > 0; j--) {
			cout << j << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n; cin >> n;

	displayPattern(n);

	return 0;
}





