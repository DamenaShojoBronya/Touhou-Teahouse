#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;

int match(int num1, int num2)
{
	int a[3], b[3];
	for (int i = 2; i >= 0; i--) {
		a[i] = num1 - num1 / 10 * 10; num1 /= 10;
		b[i] = num2 - num2 / 10 * 10; num2 /= 10;
	}

	int count = 0;

	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			if (a[i] == b[j]) { count++; break; }

	return count;
}

int main()
{
	srand(time(0));
	int rand_num = rand() % 900 + 100;
	int gues_num; cin >> gues_num;
	int mat = match(rand_num, gues_num);

	if (gues_num == rand_num) cout << "Exact match:you win $10,000";
	else
		if (mat == 3) cout << "Match all digits:you win $3000 ";
		else
			if (mat == 1 || mat == 2) cout << "Match one digits:you win $1000";
			else cout << "Sorry,no match";

			return 0;
}

