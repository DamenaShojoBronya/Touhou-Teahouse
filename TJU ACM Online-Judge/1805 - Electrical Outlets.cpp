#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a,temp,sum = 0; cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> temp;
			sum += temp-1;
		}
		cout << sum+1 << endl;
	}
	return 0;
}