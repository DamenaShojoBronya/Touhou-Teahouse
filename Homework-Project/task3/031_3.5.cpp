/* 3.5 (Find future dates) Write a program that prompts the user to enter an
integer for today¡¯s day of the week (Sunday is 0, Monday is 1, . . . , and
Saturday is 6). Also, prompt the user to enter the number of days after
today for a future day and display the future day of the week. */

#include<iostream>
using namespace std;

void day(int a)
{
	switch (a)
	{
	case 1: cout << "Monday "; break;
	case 2: cout << "Tuesday "; break;
	case 3: cout << "Wednesday "; break;
	case 4: cout << "Thursday "; break;
	case 5: cout << "Friday "; break;
	case 6: cout << "Saturday "; break;
	case 0: cout << "Sunday "; break;
	}
}

int main()
{
	int a, b;
	cout << "Enter today's day:";
	cin >> a;
	cout << "Enter the number of days elapsed since today:";
	cin >> b;

	cout << "Today is "; day(a % 7);
	cout << "and the future day is "; day(b % 7 + a);

	return 0;
}
