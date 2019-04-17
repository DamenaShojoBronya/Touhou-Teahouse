/* 1) 4.5 (Geometry: area of a regular polygon) A regular polygon is an n-sided
polygon in which all sides are of the same length and all angles have the same
degree (i.e., the polygon is both equilateral and equiangular). The formula for
computing the area of a regular polygon is. Here, s is the length of a side. Write a
program that prompts the user to enter the number of sides and their length of a
regular polygon and displays its area. 𝑥 = (𝑛 ∗ 𝑠^2) / 4 ∗ tan(𝜋/𝑛) */

#include<math.h>
#include<iostream>
#define PI 3.141592653
using namespace std;

int main()
{
	int n; double s;

	cout << "Enter the number of sides and length of a regular polygon: ";
	cin >> n >> s;
	cout << n*s*s / 4 * tan(PI / n);

	return 0;
}

