#include<iostream>
using namespace std;

int main()
{
	int num, *max = 0, *min = 0;
	cin >> num;
	int *n = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> n[i];
		if (i == 1) {
			if (n[0] > n[1]) {
				max = &n[0]; min = &n[1];
			}
			else {
				max = &n[1]; min = &n[0];
			}
		}
		if (i>1) {
			if (n[i] > *max) max = &n[i];
			if (n[i] < *min) min = &n[i];
		}
	}
	swap(*max, *min);
	for (int i = 0; i < num; i++)
		cout << n[i] << " ";

	return 0;
}

