#include <iostream>
using namespace std;

int main()
{
	while (1) {
		int mile, mark = 0;
		char code, a[20], b[20];
		while (1) {
			cin >> a;
			if (a[0] == '#') return 0;
			if (a[0] == '0') {
				cout << mark << endl; break;
			}
			cin >> b >> mile >> code;
			if (code == 'F') mark += mile * 2;
			if (code == 'B') mark += mile * 1.5;
			if (code == 'Y'&&mile < 500)  mark += 500;
			if (code == 'Y'&&mile >= 500) mark += mile;
		}
	}
	return 0;
}