#include <iostream>
#include <string>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
using namespace std;

int main()
{
	int b, c, m = 11, n = 0;

	string s1;
	while (1){
		while (1)
		{
			cin >> b;
			if (b == 0)	return 0;
			cin.get();
			getline(cin, s1);
			if (s1 == "right on") break;
			if (s1 == "too high") m = min(m, b); 
			else n = max(n, b);
		}
		if (b < m && b > n) cout << "Stan may be honest" << endl;
		else cout << "Stan is dishonest" << endl;
		m = 11; n = 0;
	}
	return 0;
}