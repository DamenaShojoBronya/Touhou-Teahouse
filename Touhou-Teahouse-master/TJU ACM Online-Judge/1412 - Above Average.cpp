#include<iomanip>
#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a,sum = 0; cin >> a;
		int *stu = new int [a];
		float average;
		for (int j = 0; j < a; j++) {
			cin >> stu[j];
			sum += stu[j];
		}
		average = sum / a; int count = 0;
		for (int j = 0; j < a; j++) {
			if (stu[j] > average) count++;
		}
		cout <<fixed<< setprecision(3) << count / (float)a*100 <<"%"<< endl;
	}
	return 0;
}