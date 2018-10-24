/* (Student major and status)Write a program that prompts the user to enter two characters and display the major and status represented in the characters.
the first character indicates the major and the second is number character 1,2,3,4,which indicates whether a student is a freshman,sophomore,junior,
or senior.Suppose the following characters are used to denote the major:
M: Mathematics
C: Computer Science
I: Information Technology */

#include<string>
#include<iostream>
using namespace std;

int main()
{
	string c;
	cout << "Enter two characters: ";
	cin >> c;

	if (c.at(0) != 'M' && c.at(0) != 'C' && c.at(0) != 'I') {
		cout << "Invalid major code" << endl;
		return 0;
	}
	if (c.at(1) != '1'&& c.at(1) != '2'&& c.at(1) != '3'&& c.at(1) != '4') {
		cout << "Invalid status code";
		return 0;
	}
	if (c.at(0) == 'M') cout << "Mathematics ";
	if (c.at(0) == 'C') cout << "Computer Science ";
	if (c.at(0) == 'I') cout << "Information Technology ";
	if (c.at(1) == '1') cout << "Freshman ";
	if (c.at(1) == '2') cout << "Sophomore ";
	if (c.at(1) == '3') cout << "Junior ";
	if (c.at(1) == '4') cout << "Senior ";

	return 0;
}

