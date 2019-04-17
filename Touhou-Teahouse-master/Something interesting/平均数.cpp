#include<iostream>
using namespace std;

int main()
{
	int a[100], i = 0;
	float t, s = 0;

	while (cin >> a[i]) {
		if (a[i] <= 0) break;
		s = s + a[i++];
	}
	t = s / i; cout << t << endl;
	for (i = 0; a[i] > 0; i++) {
		if (a[i] < t) cout << a[i] << " ";
	}

	return 0;
}
