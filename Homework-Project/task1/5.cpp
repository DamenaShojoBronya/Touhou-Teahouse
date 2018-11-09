/*	Write a program that reads the subtotoal and the gratuity rate,then computes the gratuity and total.
	For example,if the user enters 10 for subtotal and 15% for gratuity rate,the program displays $1.5 as gratuity and $11.5 as total.	*/

#include<iostream>
using namespace std;
#define RESULT subtotal*gratuity_rate/100
int main()
{
    float subtotal=0,gratuity_rate=0;
	cout<<"Enter the subtotal and gratuity rate:";
	cin>>subtotal>>gratuity_rate;
	cout<<"The gratuity is "<<RESULT<<"$"<<" and total is "<<subtotal+RESULT <<"$"<<endl;
    return 0;
}
