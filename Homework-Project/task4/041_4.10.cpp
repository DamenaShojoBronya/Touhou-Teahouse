/* 1) 4.10 (Vowel or consonant?) Assume letters A/a, E/e, I/i, O/o, and U/u as the
vowels. Write a program that prompts the user to enter a letter and check whether
the letter is a vowel or consonant. */

#include<iostream>
using namespace std;

int main()
{
	char a;

	cout << "Enter a letter: ";
	cin >> a;
	if (a<'A' || a>'z') {
		cout << "Not a letter"; return 0;
	}
	if (a == 'A' || a == 'a' || a == 'E' || a == 'e' || a == 'I' || a == 'i' || a == 'O' || a == 'o' || a == 'U' || a == 'u') {
		cout << "It's a vowel";
	}
	else cout << "It's a consonant";

	return 0;
}

