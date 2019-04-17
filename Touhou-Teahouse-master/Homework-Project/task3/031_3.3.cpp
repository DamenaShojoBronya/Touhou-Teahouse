#include<math.h>
#include<iostream>
using namespace std;

int main()
{
	float a, b, c, d, e, f;
	cout << "Enter a,b,c,d,e,f:";
	cin >> a >> b >> c >> d >> e >> f;

	if (a*d - b*c == 0) cout << "The equation has no solution.";
	else cout << "x is " << (e*d - b*f) / (a*d - b*c) << " end "
		<< "y is " << (a*f - e*c) / (a*d - b*c);

	return 0;
}

