/*Here are 5 variables:
short a;int b;long c;float d;double e;
write a program to output the sum size of variable a,b,c,d,e on your machine.*/
#include<iostream>
using namespace std;

int main()
{
	short a=sizeof(a);int b=sizeof(b);long c=sizeof(c);float d=sizeof(d);double e=sizeof(e);
	cout<<a+b+c+d+e<<endl;
	return 0;
}