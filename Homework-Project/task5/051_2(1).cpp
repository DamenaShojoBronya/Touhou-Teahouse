/*	Write a program to prompt the user input a decimal number (type:
int, number <INT_MAX) , convert the decimal number to a binary
number (type: string).
11 / 2 = 5 … 1
5 / 2 = 2 … 1
2 / 2 = 1 … 0
1 / 2 = 0 … 1
Enter a decimal number: 11
The corresponding binary number is: 1011 */

#include<string>
#include<iostream>
using namespace std;

int main()
{
	cout << "Input a decimal number(number<INT_MAX): ";
	int n; cin >> n;
	if (n == 0) printf("0");
	if (n<0) { n *= -1; printf("-"); }

	int i; string a(50, ' ');
	for (i = 0; n != 0; i++) {
		a.at(i) = n % 2 + 48; n /= 2;
	}
	while (i > 0) {
		cout << a.at(--i);
	}

	return 0;
}