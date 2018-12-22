#include<iostream>
using namespace std;

int main()
{
	long int num1, num2, m, n, sum, num;
    
	while (cin>>num1>>num2) {
		if (num1 == 0 && num2 == 0) break;
		if (num1>num2) num = num1;
		else num = num2;

		int length = 0;
		while (num != 0) { num /= 10; length++; }

		int count = 0, carry = 0;
		while (length != 0) {
			m = num1 % 10; num1 /= 10;
			n = num2 % 10; num2 /= 10;
			sum = m + n + carry;
			if (sum>=10) {
				count++;
				carry = sum / 10;
			}
			else carry = 0;
			length--;
		}

		if (count == 0) cout << "No carry operation." << endl;
		else if (count == 1) cout << "1 carry operation." << endl;
		else cout << count << " carry operations." << endl;
	}

	return 0;
}
