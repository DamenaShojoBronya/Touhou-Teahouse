#include "stdafx.h"

#include<iostream>
using namespace std;

bool QUEENS(int a[8][8]) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int i1 = 0; i1 < 8; i1++) {
			count += a[i][i1];
		}
		if (count > 1) return false;
	}
	return true;
}
int main()
{
	int a[8][8] = { 0 };
	for (int i = 0; i < 8; i++)
		a[0][i] = 1;
	if (QUEENS(a[8][8]));
	for (int i = 0; i < 8; i++) {
		for (int i1 = 0; i1 < 8; i1++)
			cout << a[i][i1] << " ";
		cout << endl;
	}

	return 0;
}





