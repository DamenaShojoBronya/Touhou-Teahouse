#include<string>
#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a; b = a;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] < 'Z') b[j]++;
			else b[j] = 'A';
		}
        cout << "String #" << i + 1 << endl
             << b << endl << endl;           //...真的假的。
    }

	return 0;
}