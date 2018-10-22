/* 3) Design three sets of numbers and write a program to find a user’s favorite day in
a week (use number 1-7 to represent from Monday to Sunday). The program
prompts the user to answer whether his/her favorite day in a week is in the three
sets of numbers you designed. */

#include<string>
#include<iostream>
using namespace std;

int main()
{
	char ans[3]; string day[3];
	day[0] = " 1 2 3 7 ";
	day[1] = " 1 4 5 7 ";
	day[2] = " 2 4 6 7 ";

	for (int i = 0; i < 3; i++) {
		cout << "Is your favorite day in Set" << i + 1 << "?" << endl
			<< day[i] << endl << "Enter Y/y for yes and N/n for not:";
		cin >> ans[i]; if (ans[i] == 'Y' || ans[i] == 'N') ans[i] = (char)ans[i] + 32;
	}

	if (ans[0] == 'y'&&ans[1] == 'y'&&ans[2] == 'n') cout << "1";
	if (ans[0] == 'y'&&ans[1] == 'n'&&ans[2] == 'y') cout << "2";
	if (ans[0] == 'y'&&ans[1] == 'n'&&ans[2] == 'n') cout << "3";
	if (ans[0] == 'n'&&ans[1] == 'y'&&ans[2] == 'y') cout << "4";
	if (ans[0] == 'n'&&ans[1] == 'y'&&ans[2] == 'n') cout << "5";
	if (ans[0] == 'n'&&ans[1] == 'n'&&ans[2] == 'y') cout << "6";
	if (ans[0] == 'y'&&ans[1] == 'y'&&ans[2] == 'y') cout << "7";
	else cout << "You have no favorite day!";

	return 0;
}

