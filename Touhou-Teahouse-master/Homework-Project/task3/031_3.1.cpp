#include<math.h>
#include<iostream>
using namespace std;

int main()
{
	float a, b, c, root;
	cout << "Please enter values for a,b,and c:";
	cin >> a >> b >> c;
	root = b*b - 4 * a*c;

	if (root == 0) cout << "root value is 1";
	else
		if (root > 0) cout << "r1 is " << (-b + sqrt(root)) / (2 * a) << ","
			<< "r1 is " << (-b - sqrt(root)) / (2 * a);
		else cout << "The equation has no real roots." << endl;

		return 0;
}