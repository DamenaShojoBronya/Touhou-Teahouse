/*  6.3 Write a function with the following header to sort three numbers in ascending order:
	void sort(double& num1,double& num2,double& num3);  */

#include<iostream>
using namespace std;

void sort(double& num1, double& num2, double& num3) {
	if (num1 > num2) swap(num1, num2);
	if (num1 > num3) swap(num1, num3);
	if (num2 > num3) swap(num2, num3);

	cout << num1 << " " << num2 << " " << num3;
}

int main()
{
	double num1,num2,num3; 
	cin >> num1 >> num2 >> num3;

	sort(num1, num2, num3);

	return 0;
}