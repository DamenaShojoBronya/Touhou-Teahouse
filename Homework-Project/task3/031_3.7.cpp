/* 3.7 (Sort three integers) Write a program that prompts the user to enter
three integers and display the integers in non-decreasing order. */
#include<iostream>
using namespace std;

int main()
{
	int a[3], i = 0, temp;
	cout << "Please input three integers:";

	while (i < 3) cin >> a[i++];

	for (int i = 0; i<2; i++)
		for (int j = 0; j < 2 - i; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);

	while (i < 6) cout << a[i++ - 3] << " ";

	return 0;
}
