/*	5.36 (Game: scissor, rock, paper) The game ends if you or the computer
win twice. */

#include<ctime>
#include<string>
#include<iostream>
using namespace std;

int game0(int u, string n) {
	if (n == "s" || n == "scissor") u = 0;
	if (n == "r" || n == "rock") u = 1;
	if (n == "p" || n == "paper") u = 2;

	return u;
}

void game1(int c) {
	if (c == 0) cout << "scissor";
	if (c == 1) cout << "rock";
	if (c == 2) cout << "paper";
}

int main()
{
	cout << "You: ";
	string n; cin >> n;
	int u = 0;
	u = game0(u, n);

	cout << "Computer: ";
	srand(time(0));
	int c = rand() % 3;
	game1(c);

	if (u == c)  cout << endl << "You draw with computer";
	if (u - c == 1 || c - u == 2)  cout << endl << "You win";
	if (c - u == 1 || u - c == 2)  cout << endl << "You lose";

	return 0;
}







