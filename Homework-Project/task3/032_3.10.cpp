/* (Game:addition quiz) Listing 3.4,SubtractionQuiz.cpp,randomly generates a subtraction question.
    Revise the program to randomly generate an addition question with two integers less than 100. */
#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;

int main()
{
	srand(time(0));
	int num1 = rand() % 100;
	int num2 = rand() % 100;
	int answer;

	cout << "what is " << num1 << " + " << num2 << "? ";
	cin >> answer;
	if (answer == num1 + num2) cout << "You are correct!";
	else cout << "Your answer is wrong." << endl
		<< num1 << " + " << num2 << " should be " << num1 + num2;

	return 0;
}

