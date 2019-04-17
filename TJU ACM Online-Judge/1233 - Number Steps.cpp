#include <iostream>
using namespace std;

int main()
{
	int n, x, y, ans[20]; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x >= 0 && y >= 0 && x == y) {
			if (x % 2 == 0) cout << x * 2;
			else cout << x * 2 - 1;
		}
		else
			if (x >= 2 && y >= 0 && x == y + 2) {
				if (x % 2 == 0) cout << x * 2 - 2;
				else cout << x * 2 - 1 - 2;
			}
			else cout << "No Number";
			cout << endl;
	}

	return 0;
}