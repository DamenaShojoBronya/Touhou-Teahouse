/* (Random strings)Write a program that generates a random string with three uppercase letters. */

#include<string>
#include<ctime>
#include<iostream>
using namespace std;

int main()
{
	srand(time(0));
	string s = "ABC";

	for (int i = 0; i < 3; i++) {
		s[i] = rand() % 26 + 'A';
	}
	cout << s;

	return 0;
}

