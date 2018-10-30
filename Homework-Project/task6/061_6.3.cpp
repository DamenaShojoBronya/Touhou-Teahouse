/*	6.3 Use reverse to implement isPalindrome. Write a test program that prompts
the user to enter an integer and reports whether it is an palindrome integer.

//Return the reversal of an integer,
//i.e., reverse(456) return 654
int reverse(int number)
//Return true if number is a palindrome
bool isPalindrome(int number) */

#include<string>
#include<iostream>
using namespace std;

bool isPalindrome(int n1, int n2) {
	for (int i = 0; n1>0; i++) {
		if (n1 - n1 / 10 * 10 != n2 - n2 / 10 * 10) return false;
		else { n1 /= 10; n2 /= 10; }
	}
	return true;
}

int reserve(int n1) {
	int n2[100], temp = 0, i;

	for (i = 0; n1 > 0; i++) {
		n2[i] = n1 - n1 / 10 * 10;
		n1 = n1 / 10;
	}
	for (int i2 = 0; i2<i; i2++) temp = temp * 10 + n2[i2];

	return temp;
}

int main()
{
	cout << "Enter an integer" << endl;
	int n1; cin >> n1;
	int n2 = reserve(n1);

	if (isPalindrome(n1, n2) == true) cout << "It is an palindrome integer";
	else cout << "It isn't an palindrome integer";

	return 0;
}





