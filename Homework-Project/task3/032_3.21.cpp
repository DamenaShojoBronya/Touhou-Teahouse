/* (Game:pick a card) Write a program that simulates picking a card from a desk of 52 cards.
    Your program should display the rank (Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King) and suit (Clubs,Diamonds,Hearts,Spades) of the card. */

#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;

void print(int a)
{
	switch (a)
	{
	case 1: cout << "Ace";     break;
	case 2: cout << "Clubs";   break;
	case 3: cout << "Diamonds";break;
	case 4: cout << "Hearts";  break;
	case 5: cout << "Spades";  break;
	case 11:cout << "Jack";    break;
	case 12:cout << "Queen";   break;
	case 13:cout << "King";    break;
	}
}

int main()
{
	srand(time(0));
	int rank = rand() % 13 + 1;
	int suit = rand() % 4 + 2;

	cout << "The card you picked is ";
	if (rank == 1 || rank > 10) print(rank);
	else cout << rank;
	cout << " of ";print(suit);

	return 0;
}

