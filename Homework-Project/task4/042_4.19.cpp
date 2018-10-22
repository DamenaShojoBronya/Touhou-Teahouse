/* (Order three cities)Write a program that prompts the user to enter three cities and display them in ascending order. */

#include<string>
#include<iostream>
using namespace std;
int main()
{
	string city[3];

	cout << "Enter the first city: ";
	cin >> city[0];
	cout << "Enter the second city: ";
	cin >> city[1];
	cout << "Enter the third city: ";
	cin >> city[2];

	if (city[0].at(0) > city[1].at(0)) swap(city[0], city[1]);
	if (city[0].at(0) > city[2].at(0)) swap(city[0], city[2]);
	if (city[1].at(0) > city[2].at(0)) swap(city[1], city[2]);

	cout << "The three cities in alphabetical order are " << city[0] << " " << city[1] << " " << city[2];

	return 0;
}

