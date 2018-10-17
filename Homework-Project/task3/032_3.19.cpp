/* Write a program that prompts the user to enter a point (x,y) and checks whether the point is within the circle centered at (0,0) with radius 10.
For example,(4,5) is inside the circle and (9.9) is outside the circle. */

#include<iostream>
using namespace std;

int main()
{
	float a, b;
	cout << "Input the point (x,y):";
	cin >> a >> b;

	if (a*a + b*b <= 100) cout << "Inside the circle.";
	else cout << "Outside the circle.";

	return 0;
}