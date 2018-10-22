/* Write a program to prompt the user input a decimal number(number<INT_MAX),convert the number to a binary number. */

#include<string>
#include<iostream>
using namespace std;

int main()
{
	cout << "Input a decimal number(number<INT_MAX): ";
	int n; cin >> n;
	if (n == 0) printf("0");
	if (n<0) { n *= -1; printf("-"); }

	int i, a[100];
	for (i = 0; n != 0; i++) {
		a[i] = n % 2; n /= 2;
	}
	while (i > 0) {
		cout << a[i - 1]; i--;
	}

	return 0;
}

