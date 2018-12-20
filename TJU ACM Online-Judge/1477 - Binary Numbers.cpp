#include<iostream>
using namespace std;
void Binary(int m) {
	int mylist[30];
	for (int i = 0; i < 100; i++) {
		mylist[i] = m % 2;
		m /= 2;
		if (m == 0) {
			mylist[i+1] = -1; break;
		}
	}
	int p = 0;
	for (int j = 0; mylist[j] != -1; j++) {
		if (p == 0 && mylist[j] == 1) {
			cout << j; p = 1; j++;
		}
		if (p == 1 && mylist[j] == 1) cout << " " << j;
	}
}

int main()
{
	int d, x;
	cin >> d;

	for (; d > 0; d--) {
		cin >> x;
		Binary(x);
		cout << endl;
	}

	return 0;
}