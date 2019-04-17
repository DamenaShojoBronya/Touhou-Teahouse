/* (Check SSN)Write a program that prompts the user to enter a School Security number in the format ddd-dd-dddd,
where d is a digit.Your program should check whether the input is valid. */

#include<string>
#include<iostream>
using namespace std;

int main()
{
	string ssn;
	cout << "Enter a SSN: ";
	cin >> ssn;
	if (ssn.at(3) != '-' || ssn.at(6) != '-') cout << ssn << " is a invalid social security number";
	else cout << ssn << " is a valid social security number";

	return 0;
}



