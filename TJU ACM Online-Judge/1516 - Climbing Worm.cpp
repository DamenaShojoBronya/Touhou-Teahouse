#include<iostream>
using namespace std;

int main()
{
	int n, u, d, temp = 0, output[10] = { 0 }, count = 0;

	while (cin >> n >> u >> d) {
		if (n != 0) {
			for (int i = 0;;) {
				if (temp >= n) { output[count++] = i; break; }
				temp += u; i++;
				if (temp >= n) { output[count++] = i; break; }
				temp -= d; i++;
			}
			n, u, d, temp = 0;
		}
		else break;
	}

	for (int i = 0; output[i] != NULL; i++)
		cout << output[i] << endl;

	return 0;
}