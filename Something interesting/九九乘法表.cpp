#include<iomanip>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	cout << "        1     2     3     4     5     6     7     8     9" << endl
		<< "---------------------------------------------------------" << endl;

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (j == 1) cout << i*j << " Ø­"; //ºº×ÖÊú£¬xswl
			cout << setw(5) << i*j << " ";
		}
		cout << endl;
	}

	return 0;
}



