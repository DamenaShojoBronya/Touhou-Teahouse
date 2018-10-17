/* (Geometry:two rectangles) Write a program that prompts the user to enter the center x-,y-coordinates,
width,and height of two rectangles and determines whether the second rectangle is inside the first or overlaps with the first,
as shown in Figure 3.9.Test your program to cover all cases. */

#include<math.h>
#include<iostream>
using namespace std;

int main()
{
	float x1, x2, y1, y2, w1, w2, h1, h2;
	cout << "Enter r1's center x-,y-coordinates,width,and height:";
	cin >> x1 >> y1 >> w1 >> h1;
	cout << "Enter r2's center x-,y-coordinates,width,and height:";
	cin >> x2 >> y2 >> w2 >> h2;

	if (fabs(x1 - x2) < fabs(w1 / 2 - w2 / 2) || fabs(y1 - y2) < fabs(h1 / 2 - h2 / 2)) cout << "r2 is inside r1";
	else
		if (fabs(x1 + x2) <= fabs(w1 / 2 + w2 / 2) || fabs(y1 + y2) <= fabs(h1 / 2 + h2 / 2) || w1 < w2 || h1 < h2) cout << "r2 overlap r1";
		else cout << "r2 does not overlap r1";

		return 0;
}