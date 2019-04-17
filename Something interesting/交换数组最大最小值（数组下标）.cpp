#include<iostream>
using namespace std;

int main()
{
	int num, max, min, a = 0, b = 0;
	cin >> num;
	int *n = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> n[i];
		if (i == 0) {
			max = n[0]; min = n[0];

		}
		if (i>0) {
			if (n[i] > max) { max = n[i]; a = i; }
			if (n[i] < min) { min = n[i]; b = i; }
		}
	}
	swap(n[a], n[b]);
	for (int i = 0; i < num; i++)
		cout << n[i] << " ";

	return 0;
}



