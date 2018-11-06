#include<ctime>
#include<iostream>
#define PI b*4/a;
using namespace std;

int main()
{
	srand(time(0));
	double a = 0, b = 0;

	for (int i = 0; i < 1000000; i++) {
		double x = rand() / (double)RAND_MAX;
		double y = rand() / (double)RAND_MAX;
		a++;
		if (sqrt(x*x + y*y) <= 1) b++;
	}

	cout << PI;

	return 0;
}



