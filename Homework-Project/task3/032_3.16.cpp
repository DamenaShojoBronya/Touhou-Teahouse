/* (Compute the perimeter of a triangle)Write a program that reads three edges for a triangle and computes the perimeter if the input is valid.
Otherwise,display that the input is invalid.The input is valid if the sum of every pair of two edges is greater than the remaining edge. */

#include<iostream>
using namespace std;

int main()
{
	float a, b, c, max;
	cin >> a >> b >> c;
	max = (a > b) ? a : (b > c) ? b : c;

	if (a + b + c <= 2 * max) cout << "The input is invalid.";
	else cout << "The perimeter is " << a + b + c << ".";

	return 0;
}