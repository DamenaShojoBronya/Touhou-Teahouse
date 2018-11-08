/*  (Optional)Write a test program that prompts the user to enter a phone number as a string.
	The program translates a letter(uppercase or lowercase) to a digit and leaves all other characters intact. */

#include<string>
#include<iostream>
using namespace std;

int keyboard(string& str){
	int num = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) >='A' && str.at(i) <= 'Z') str.at(i) += 32;
		if (str.at(i) =='a' || str.at(i) == 'b' || str.at(i) == 'c') num = num*10+2;
		if (str.at(i) =='d' || str.at(i) == 'e' || str.at(i) == 'f') num = num*10+3;
		if (str.at(i) =='g' || str.at(i) == 'h' || str.at(i) == 'i') num = num*10+4;
		if (str.at(i) =='j' || str.at(i) == 'k' || str.at(i) == 'l') num = num*10+5;
		if (str.at(i) =='m' || str.at(i) == 'n' || str.at(i) == 'o') num = num*10+6;
		if (str.at(i) =='t' || str.at(i) == 'u' || str.at(i) == 'v') num = num*10+8;
		if (str.at(i) =='p' || str.at(i) == 'q' || str.at(i) == 'r'|| str.at(i) == 's') num = num*10+7;
		if (str.at(i) =='w' || str.at(i) == 'x' || str.at(i) == 'y'|| str.at(i) == 'z') num = num*10+9;
	}

	return num;
}
int main()
{
	string str;
	cin >> str;
	cout << keyboard(str);

	return 0;
}






