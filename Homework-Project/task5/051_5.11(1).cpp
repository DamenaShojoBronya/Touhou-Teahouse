/*	5.11 (Find the two highest scores) Write a program that prompts
the user to enter the number of students and each student’s score
and name, and finally displays the name and score of the student
with the highest score and the student with the second-highest
score. (cin.get()) */

#include<string>
#include<iostream>
using namespace std;

int main()
{
	cout << "Enter the number of students: ";
	int n; cin >> n;
	string *name = new string[n];
	int *score = new int[n];
	cout << "Enter the name and score of each student:" << endl;

	for (int i = 0; i < n; i++) {
		cin.get();                  //eat the \n
		getline(cin, name[i], ' ');  //set up ' ' as the end of string //...so using getline is totally unnecessary
		cin >> score[i];
	}
	for (int i = 0; i<n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (score[j] < score[j + 1]) {
				swap(name[j], name[j + 1]);
				swap(score[j], score[j + 1]);
			}

	cout << "The top student's name is: " << name[0] << ",and score is: " << score[0] << endl;
	cout << "The second student's name is: " << name[1] << ",and score is: " << score[1];

	return 0;
}