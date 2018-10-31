/*	5.49 (Longest common prefix) Write a program that prompts the user to
enter two strings and displays the largest common prefix of the two
strings. */

#include<string>
#include<iostream>
using namespace std;

int main()
{
	string str[2];
	cin >> str[0];
	cin >> str[1];

	for (int i = 0; i<str[0].length() && i<str[1].length(); i++) {
		if (str[0].at(i) == str[1].at(i)) cout << str[0].at(i);
		else break;
	}

	return 0;
}













