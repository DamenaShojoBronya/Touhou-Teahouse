#include <iostream>
using namespace std;

int main()
{
	int n,a=1, b = 1,count=1;
	
	while (cin >> n) {
		for (int i = 1; i < n; i++) {
			b = i; a = i;
			for (int j = 1; j <= i; j++) {
				if (i % 2 == 0) {
					if (count == n) {
						cout << "TERM " << n << " IS ";
						cout << j << "/" << b-- << endl;
						count = 1; goto quit;
					}
					else { count++; b--; }
				}
				else {
					if (count == n) {
						cout << "TERM " << n << " IS ";
						cout << a-- << "/" << j << endl;
						count = 1; goto quit;
					}
					else { count++; a--; }
				}
			}
		}
	quit:continue;
	}
	
	return 0;
}
